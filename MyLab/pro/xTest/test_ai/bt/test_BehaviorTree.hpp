
#include <vector>
#include "BehaviorShared.h"
#include "BehaviorTest.h"

namespace bt
{

enum Status
/**
 * Return values of and valid states for behaviors.
 */
{
    BH_INVALID,
    BH_SUCCESS,
    BH_FAILURE,
    BH_RUNNING,
    BH_ABORTED,
};

class Behavior
/**
 * Base class for actions, conditions and composites.
 */
{
public:
    virtual Status update()				= 0;

    virtual void onInitialize()			{}
    virtual void onTerminate(Status)	{}

    Behavior()
    :   m_eStatus(BH_INVALID)
    {
    }

    virtual ~Behavior()
    {
    }

    Status tick()
    {
        if (m_eStatus != BH_RUNNING)
        {
            onInitialize();
        }

        m_eStatus = update();

        if (m_eStatus != BH_RUNNING)
        {
            onTerminate(m_eStatus);
        }
        return m_eStatus;
    }

    void reset()
    {
        m_eStatus = BH_INVALID;
    }

    void abort()
    {
        onTerminate(BH_ABORTED);
        m_eStatus = BH_ABORTED;
    }

    bool isTerminated() const
    {
        return m_eStatus == BH_SUCCESS  ||  m_eStatus == BH_FAILURE;
    }

    bool isRunning() const
    {
        return m_eStatus == BH_RUNNING;
    }

    Status getStatus() const
    {
        return m_eStatus;
    }

private:
    Status m_eStatus;
};

// ----------------------------------------------------------------------------

struct MockBehavior : public Behavior
{
    int m_iInitializeCalled;
    int m_iTerminateCalled;
    int m_iUpdateCalled;
    Status m_eReturnStatus;
    Status m_eTerminateStatus;

    MockBehavior()
    :	m_iInitializeCalled(0)
    ,	m_iTerminateCalled(0)
    ,	m_iUpdateCalled(0)
    ,	m_eReturnStatus(BH_RUNNING)
    ,	m_eTerminateStatus(BH_INVALID)
    {
    }

    virtual ~MockBehavior()
    {
    }

    virtual void onInitialize()
    {
        ++m_iInitializeCalled;
    }

    virtual void onTerminate(Status s)
    {
        ++m_iTerminateCalled;
        m_eTerminateStatus = s;
    }
    
    virtual Status update()
    {
        ++m_iUpdateCalled;
        return m_eReturnStatus;
    }
};

// ============================================================================

class Decorator : public Behavior
{
protected:
    Behavior* m_pChild;

public:
    Decorator(Behavior* child) : m_pChild(child) {}
};

class Repeat : public Decorator
{
public:
	Repeat(Behavior* child)
	:	Decorator(child)
	{
	}

    void setCount(int count)
    {
        m_iLimit = count;
    }

    void onInitialize() 
    {
        m_iCounter = 0;
    }

    Status update() 
    {
        for (;;)
        {
            m_pChild->tick();
            if (m_pChild->getStatus() == BH_RUNNING) break;
            if (m_pChild->getStatus() == BH_FAILURE) return BH_FAILURE;
            if (++m_iCounter == m_iLimit) return BH_SUCCESS;
            m_pChild->reset();
        }
        return BH_INVALID;
    }

protected:
    int m_iLimit;
    int m_iCounter;
};

// ============================================================================

class Composite : public Behavior
{
public:
    void addChild(Behavior* child) { m_Children.push_back(child); }
    void removeChild(Behavior*);
    void clearChildren();
protected:
    typedef std::vector<Behavior*> Behaviors;
    Behaviors m_Children;
};

class Sequence : public Composite
{
protected:
    virtual ~Sequence()
    {
    }

    virtual void onInitialize()
    {
        m_CurrentChild = m_Children.begin();
    }

    virtual Status update()
    {
        // Keep going until a child behavior says it's running.
        for (;;)
        {
            Status s = (*m_CurrentChild)->tick();

            // If the child fails, or keeps running, do the same.
            if (s != BH_SUCCESS)
            {
                return s;
            }

            // Hit the end of the array, job done!
            if (++m_CurrentChild == m_Children.end())
            {
                return BH_SUCCESS;
            }
        }
    }

    Behaviors::iterator m_CurrentChild;
};

// ----------------------------------------------------------------------------

template <class COMPOSITE>
class MockComposite : public COMPOSITE
{
public:
    MockComposite(size_t size)
    {
        for (size_t i=0; i<size; ++i)
        {
            COMPOSITE::m_Children.push_back(new MockBehavior);
        }
    }

    ~MockComposite()
    {
        for (size_t i=0; i<COMPOSITE::m_Children.size(); ++i)
        {
            delete COMPOSITE::m_Children[i];
        }
    }

    MockBehavior& operator[](size_t index)
    {
        ASSERT(index < COMPOSITE::m_Children.size());
        return *static_cast<MockBehavior*>(COMPOSITE::m_Children[index]);
    }
};

typedef MockComposite<Sequence> MockSequence;

// ============================================================================

class Selector : public Composite
{
protected:
    virtual ~Selector()
    {
    }

    virtual void onInitialize()
    {
        m_Current = m_Children.begin();
    }

    virtual Status update()
    {
        // Keep going until a child behavior says its running.
		for (;;)
        {
            Status s = (*m_Current)->tick();

            // If the child succeeds, or keeps running, do the same.
            if (s != BH_FAILURE)
            {
                return s;
            }

            // Hit the end of the array, it didn't end well...
            if (++m_Current == m_Children.end())
            {
                return BH_FAILURE;
            }
        }
    }

    Behaviors::iterator m_Current;
};

// ----------------------------------------------------------------------------

typedef MockComposite<Selector> MockSelector;

class Parallel : public Composite
{
public:
    enum Policy
    {
        RequireOne,
        RequireAll,
    };

    Parallel(Policy forSuccess, Policy forFailure)
    :	m_eSuccessPolicy(forSuccess)
    ,	m_eFailurePolicy(forFailure)
    {
    }

    virtual ~Parallel() {}

protected:
    Policy m_eSuccessPolicy;
    Policy m_eFailurePolicy;

    virtual Status update()
    {	
        size_t iSuccessCount = 0, iFailureCount = 0;

        for (Behaviors::iterator it = m_Children.begin(); it != m_Children.end(); ++it)
        {
            Behavior& b = **it;
            if (!b.isTerminated())
            {
                b.tick();
            }

            if (b.getStatus() == BH_SUCCESS)
            {
                ++iSuccessCount;
                if (m_eSuccessPolicy == RequireOne)
                {
                    return BH_SUCCESS;
                }
            }

            if (b.getStatus() == BH_FAILURE)
            {
                ++iFailureCount;
                if (m_eFailurePolicy == RequireOne)
                {
                    return BH_FAILURE;
                }
            }
        }

        if (m_eFailurePolicy == RequireAll  &&  iFailureCount == m_Children.size())
        {
            return BH_FAILURE;
        }

        if (m_eSuccessPolicy == RequireAll  &&  iSuccessCount == m_Children.size())
        {
            return BH_SUCCESS;
        }

        return BH_RUNNING;
    }

    virtual void onTerminate(Status)
    {
        for (Behaviors::iterator it = m_Children.begin(); it != m_Children.end(); ++it)
        {
            Behavior& b = **it;
            if (b.isRunning())
            {
                b.abort();
            }
        }
    }
};


class Monitor : public Parallel
{
public:
	Monitor()
	:	Parallel(Parallel::RequireOne, Parallel::RequireOne)
	{
	}

	void addCondition(Behavior* condition)
    {
        m_Children.insert(m_Children.begin(), condition);
    }

    void addAction(Behavior* action)
    {
        m_Children.push_back(action);
    }
};


// ============================================================================

class ActiveSelector : public Selector
{
protected:

    virtual void onInitialize()
    {
        m_Current = m_Children.end();
    }

    virtual Status update()
    {
        Behaviors::iterator previous = m_Current;

        Selector::onInitialize();
        Status result = Selector::update();

        if (previous != m_Children.end()  &&  m_Current != previous)
        {
            (*previous)->onTerminate(BH_ABORTED);
        }
        return result;
    }
};

typedef MockComposite<ActiveSelector> MockActiveSelector;


} // namespace bt
