/*
A* Algorithm Implementation using STL is
Copyright (C)2001-2005 Justin Heyes-Jones

A* Algorithm Implementation not using STL is
Copyright (C)2008 Konstantin Stupnik
Optimized version of original implementation.


Permission is given by the author to freely redistribute and
include this code in any program as long as this credit is
given where due.

COVERED CODE IS PROVIDED UNDER THIS LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED,
INCLUDING, WITHOUT LIMITATION, WARRANTIES THAT THE COVERED CODE
IS FREE OF DEFECTS, MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE
OR NON-INFRINGING. THE ENTIRE RISK AS TO THE QUALITY AND
PERFORMANCE OF THE COVERED CODE IS WITH YOU. SHOULD ANY COVERED
CODE PROVE DEFECTIVE IN ANY RESPECT, YOU (NOT THE INITIAL
DEVELOPER OR ANY OTHER CONTRIBUTOR) ASSUME THE COST OF ANY
NECESSARY SERVICING, REPAIR OR CORRECTION. THIS DISCLAIMER OF
WARRANTY CONSTITUTES AN ESSENTIAL PART OF THIS LICENSE. NO USE
OF ANY COVERED CODE IS AUTHORIZED HEREUNDER EXCEPT UNDER
THIS DISCLAIMER.

Use at your own risk!

*/

#ifndef __ASTARSEARCH_HPP__
#define __ASTARSEARCH_HPP__

#include "IntrHeapHash.hpp"
#ifdef _DEBUG
#include "assert.h"
#endif

#define AutoUseDynamicStepLimit			(50)		// �Զ���̬���벽������
#define AutoUseDynamicDistanceLimit		(300)		// �Զ���̬�����������

#include "rts/IAStarMap.h"

template <class UserState>
class AStarSearch
{

public: // data

	enum
	{
		SEARCH_STATE_NOT_INITIALISED,
		SEARCH_STATE_SEARCHING,
		SEARCH_STATE_SUCCEEDED,
		SEARCH_STATE_FAILED,
		SEARCH_STATE_OUT_OF_MEMORY,
		SEARCH_STATE_INVALID
	};

protected:
	// A node represents a possible state in the search
	// The user provided state type is included inside this type

	enum Node_State
	{
		eNormal = 0,
		eInOpenList = 1,
		eInCloseList = 2,
	};

	struct Node : public IntrHeapHashNodeBase
	{
		Node *parent; // used during the search to record the parent of successor nodes
		Node *child; // used after the search for the application to view the search in reverse

		int g; // cost of this node + it's predecessors
		int h; // heuristic estimate of distance to goal
		int f; // sum of cumulative cost of predecessors and self and heuristic

		Node_State m_eNodeState;
		const UserState* m_UserState;
		bool m_bUseDynamic;			// ʹ�ö�̬����
      bool m_bUseDynamicEx;			// ʹ����չ��̬����

		//used in AllocateNode
		void clear()
		{
			parent=0;
			child=0;
			g=0;
			h=0;
			f=0;

		m_bUseDynamic  = false;
        m_bUseDynamicEx=false;
		m_eNodeState = eNormal;
      }

		bool IsInOpenList() { return m_eNodeState == eInOpenList; }
		bool IsInCloseList() { return m_eNodeState == eInCloseList; }
	};


	// Both hashset and heaphash use this traits of node

	struct NodeTraits{
		static bool Compare(const Node* x,const Node* y)
		{
			return x->f < y->f;
		}
		static bool isEqual(const Node* x,const Node* y)
		{
			return x->m_UserState->IsSameState(*y->m_UserState);
		}
		static uint32_t getHashCode(const Node* x)
		{
			return x->m_UserState->getHashCode();
		}
	};

public: // methods


  // constructor just initialises private data
  AStarSearch() :
    m_State( SEARCH_STATE_NOT_INITIALISED ),
    m_CurrentSolutionNode( NULL ),
    m_CancelRequest( false )
  {
    InitPool();
    m_agentCellSize=1;
    m_staticObstacle=true;
    m_dynamicObstacle=true;
    m_dynamicObstacleEx = false;
    m_successNum=0;

	m_bAutoUseDynamic = UserSet;
  }

		~AStarSearch()
		{
			// if additional pool page was allocated, let's free it
			NodePoolPage* page=defaultPool.nextPage;
			while(page)
			{
				NodePoolPage* next=page->nextPage;
				delete page;
				page=next;
			}
			// 	  std::vector<NodePoolPage*>::iterator it =  vecpoolpage.begin();
			// 	  int i = vecpoolpage.size();
			// 	  for (; it != vecpoolpage.end();)
			// 	  {
			// 		  NodePoolPage* page = *it;
			// 		  it = vecpoolpage.erase(it);
			// 		  delete page;
			// 	  }
		}


		void NodeLink(Node* n)
		{
			m_nUnUseDynamicNodes = 0;
			// set the child pointers in each node (except Goal which has no child)
			Node *nodeChild = n;
			Node *nodeParent = n->parent;
			do
			{
				if (!nodeParent)
				{
					break;
				}

		  // ����δʹ�ö�̬����Node����
		  if (!nodeChild->m_bUseDynamic && !nodeChild->m_bUseDynamicEx)
			  m_nUnUseDynamicNodes++;

				nodeParent->child = nodeChild;

				nodeChild = nodeParent;
				nodeParent = nodeParent->parent;

			}while( nodeChild != m_Start ); // Start is always the first node by definition
		}

		// call at any time to cancel the search
		void CancelSearch()
		{
			m_CancelRequest = true;

			if( !NodeTraits::isEqual(m_NearstGoal, m_Start) )
			{
				NodeLink(m_NearstGoal);
			}

		}

		// Set Start and goal states
		void SetStartAndGoalStates( const UserState &Start, const UserState &Goal )
		{
			// Reinit nodes pool after previous searches
			InitPool();

			// Clear containers after previous searches
			m_OpenList.Clear();
			m_ClosedList.Clear();

			m_CancelRequest = false;

			// allocate start end goal nodes
			m_Start = AllocateNode();
			m_Goal = AllocateNode();

			m_Start->m_UserState = &Start;
			m_Goal->m_UserState = &Goal;

			m_NearstGoal = m_Start;

			m_State = SEARCH_STATE_SEARCHING;

			// Initialise the AStar specific parts of the Start Node
			// The user only needs fill out the state information

			m_Start->g = 0;
			m_Start->h = m_Start->m_UserState->GoalDistanceEstimate( *m_Goal->m_UserState );
			m_Start->f = m_Start->g + m_Start->h;
			m_Start->parent = 0;

			// Push the start node on the Open list

			m_OpenList.Insert( m_Start );
			m_Start->m_eNodeState = eInOpenList;

			// Initialise counter for search steps
			m_Steps = 0;
		}

		// Advances search one step
		unsigned int SearchStep()
		{
			// Firstly break if the user has not initialised the search

			// Next I want it to be safe to do a searchstep once the search has succeeded...
			if( (m_State == SEARCH_STATE_SUCCEEDED) ||
				(m_State == SEARCH_STATE_FAILED)
				)
			{
				return m_State;
			}

			// Failure is defined as emptying the open list as there is nothing left to
			// search...
			// New: Allow user abort
			if( m_OpenList.isEmpty() || m_CancelRequest )
			{
				NodeLink(m_NearstGoal);
				m_State = SEARCH_STATE_FAILED;
				return m_State;
			}

			// Incremement step count
			m_Steps ++;

			// Pop the best node (the one with the lowest f)
			Node *n= m_OpenList.Pop();
			n->m_eNodeState = eNormal;

	// ���ݹ������ö�\��̬����
	if (m_bAutoUseDynamic == AutoDynamic)
	{
		m_staticObstacle = true;
        n->m_bUseDynamicEx = false;
		if (m_Steps < AutoUseDynamicStepLimit || n->g < AutoUseDynamicDistanceLimit)
			n->m_bUseDynamic = true;
		else
			n->m_bUseDynamic = false;
	}
    else if (m_bAutoUseDynamic == AutoDynamicEx)
    {
        m_staticObstacle = true;
        n->m_bUseDynamic = false;
        if (m_Steps < AutoUseDynamicStepLimit || n->g < AutoUseDynamicDistanceLimit)
            n->m_bUseDynamicEx = true;
        else
            n->m_bUseDynamicEx = false;
    }
	else
	{
        m_staticObstacle = true;
		n->m_bUseDynamic = m_dynamicObstacle;
        n->m_bUseDynamicEx = m_dynamicObstacleEx;
	}

			// Check for the goal, once we pop that we're done
			if (NodeTraits::isEqual(n, m_Goal))
			{
				// The user is going to use the Goal Node he passed in
				// so copy the parent pointer of n
				m_Goal->parent = n->parent;

				// A special case is that the goal was passed in as the start state
				// so handle that here
				if (!NodeTraits::isEqual(n, m_Start))
				{
					NodeLink(n);
				}

				m_State = SEARCH_STATE_SUCCEEDED;

				return m_State;
			}
			else // not goal
			{

				// We now need to generate the successors of this node
				// The user helps us to do this, and we keep the new nodes in
				// m_Successors ...

				//       m_Successors.clear(); // empty vector of successor nodes to n
				m_successNum=0;

      // User provides this functions and uses AddSuccessor to add each successor of
      // node 'n' to m_Successors
      n->m_UserState->GetSuccessors( this, n->parent ? n->parent->m_UserState : NULL ,m_agentCellSize,m_staticObstacle, n->m_bUseDynamic,n->m_bUseDynamicEx);

				// Now handle each successor to the current node ...
				//       for( typename std::vector< Node * >::iterator successor = m_Successors.begin(); successor != m_Successors.end(); successor ++ )
				for( int i=0;i<m_successNum; ++i )
				{
					Node * successor = m_Successors[i];
					//  The g value for this successor ...
					int newg = n->g + n->m_UserState->GetCost( *(successor->m_UserState) );
					// int newg = 0;
					// �����кܴ���߿ռ䣬�������5-6��Ч�ʣ�������hash��Ч�����⣬������

					// Now we need to find whether the node is on the open or closed lists
					// If it is but the node that is already on them is better (lower g)
					// then we can forget about this successor

					if (successor->IsInOpenList() && successor->g <= newg )
					{
						continue;
					}

					if (successor->IsInCloseList() && successor->g <= newg)
					{
						continue;
					}

					// This node is the best node so far with this particular state
					// so lets keep it and set up its AStar specific data ...

					successor->parent = n;
					successor->g = newg;
					successor->h = successor->m_UserState->GoalDistanceEstimate( *m_Goal->m_UserState );
					successor->f = successor->g + successor->h;

					// Remove successor from closed if it was on it

					if (successor->IsInCloseList())
					{
						m_ClosedList.Delete( *successor );
					}

					if (successor->IsInOpenList())
					{
						m_OpenList.Delete( *successor );
					}

					m_OpenList.Insert( successor );
					successor->m_eNodeState = eInOpenList;
				}

				// push n onto Closed, as we have expanded it now
				if(m_NearstGoal->h>n->h)
				{
					m_NearstGoal = n;
				}

				m_ClosedList.Insert( n );
				n->m_eNodeState = eInCloseList;

			} // end else (not goal so expand)

			return m_State; // Succeeded bool is false at this point.

		}

		// User calls this to add a successor to a list of successors
		// when expanding the search frontier
		bool AddSuccessor( const UserState* State )
		{
			if (m_successNum >= maxSuccessorsNum)
				return false;

			Node *node = NULL;

			Node* openlist_result = NULL;
			typename NodeHash::Iterator closedlist_result(NULL);

			openlist_result = m_OpenList.Find2(*State);
			if (!openlist_result)
				closedlist_result=m_ClosedList.Find(*State);

			if (openlist_result)
			{
				node = openlist_result;
			}
			else if (closedlist_result.Found())
			{
				node = closedlist_result.Get();
			}
			else
			{
				node = AllocateNode();
				if (!node)
					return false;

				node->m_UserState = State;
			}

			m_Successors[m_successNum++]=node;
			return true;

			//       m_Successors.push_back( node );
		}

		// Functions for traversing the solution

		// Get start node
		const UserState *GetSolutionStart()
		{
			m_CurrentSolutionNode = m_Start;
			if( m_Start )
			{
				return m_Start->m_UserState;
			}
			else
			{
				return NULL;
			}
		}

		// Get next node
		const UserState *GetSolutionNext()
		{
			if( m_CurrentSolutionNode )
			{
				if( m_CurrentSolutionNode->child )
				{
#ifdef _DEBUG
					if (m_CurrentSolutionNode->child == m_CurrentSolutionNode)
					{
						assert(0&&"astar error!!!!!!");
						return NULL;
					}
#endif
					m_CurrentSolutionNode = m_CurrentSolutionNode->child;

					return m_CurrentSolutionNode->m_UserState;
				}
			}

			return NULL;
		}

		// Get end node
		const UserState *GetSolutionEnd()
		{
			if (m_CancelRequest)
				m_CurrentSolutionNode = m_NearstGoal;
			else
				m_CurrentSolutionNode = m_Goal;

			if (!m_CurrentSolutionNode)
				return NULL;

			return m_CurrentSolutionNode->m_UserState;
		}

		// Step solution iterator backwards
		const UserState *GetSolutionPrev()
		{
			if( m_CurrentSolutionNode )
			{
				if( m_CurrentSolutionNode->parent )
				{

					m_CurrentSolutionNode = m_CurrentSolutionNode->parent;

					return m_CurrentSolutionNode->m_UserState;
				}
			}

			return NULL;
		}

		// Get the number of steps

		int GetStepCount()
		{
			return m_Steps;
		}

		int GetUnUseDynamicNodeCount()
		{
			return m_nUnUseDynamicNodes;
		}

private: // methods


	// Node memory management
	Node *AllocateNode()
	{
		if(freeNodesList)
		{
			Node* rv=freeNodesList;
			freeNodesList=freeNodesList->child;
			rv->clear();
			return rv;
		}
		if(currentPoolPage->nextFreeNode==currentPoolPage->endFreeNode)
		{
			if (!currentPoolPage->nextPage)
			{
				currentPoolPage->nextPage=new NodePoolPage;
				//            vecpoolpage.push_back(currentPoolPage->nextPage);
			}

			currentPoolPage=currentPoolPage->nextPage;
		}
		Node* rv=currentPoolPage->nextFreeNode++;
		rv->clear();
		return rv;
	}

	void FreeNode( Node *node )
	{
		node->child=freeNodesList;
		freeNodesList=node;
	}

private: // data

	//private copy constructor
	//class cannot be copied
	AStarSearch(const AStarSearch&);

	//both containers are intrusive containers.
	//i.e. all fields required for container are
	//already in Node thru inheritance.
	//this minimizes memory allocations.

	// binary heap and hashset '2 in 1' container with 'open' nodes

	typedef IntrHeapHash<Node, UserState, NodeTraits> NodeHeap;
	NodeHeap m_OpenList;

	// hashset for 'closed' nodes
	typedef IntrHashSet<Node, UserState, NodeTraits> NodeHash;
	NodeHash m_ClosedList;

	// Successors is a vector filled out by the user each type successors to a node
	// are generated
	//   typedef std::vector< Node * > NodeVector;
	//   NodeVector m_Successors;
	enum{maxSuccessorsNum=8};
	int m_successNum;
	Node* m_Successors[maxSuccessorsNum];

	//default page size
	enum{nodesPerPage=1024};

	// page of pool of nodes for fast allocation
	struct NodePoolPage{
		Node nodes[nodesPerPage];
		Node* nextFreeNode;
		Node* endFreeNode;
		NodePoolPage* nextPage;
		NodePoolPage()
		{
			Init();
			nextPage=0;
		}
		void Init()
		{
			nextFreeNode=nodes;
			endFreeNode=nodes+nodesPerPage;
		}
	};

	//first page of pool allocated along with AStarSearch object on stack
	//or in data segement if static.
	//should be enough for most tasks
	NodePoolPage defaultPool;
	//pointer to current pool page. equal to address of default pool at start
	NodePoolPage* currentPoolPage;
	//pointer to first node of linked list of nodes
	Node* freeNodesList;
	//std::vector<NodePoolPage*> vecpoolpage;

	void InitPool()
	{
		currentPoolPage=&defaultPool;
		freeNodesList=0;
		NodePoolPage* ptr=currentPoolPage;
		while(ptr)
		{
			ptr->Init();
			ptr=ptr->nextPage;
		}
	}

	// State
	unsigned int m_State;

	// Counts steps
	int m_Steps;

	// Start and goal state pointers
	Node *m_Start;
	Node *m_Goal;
	Node *m_CurrentSolutionNode;

	bool m_CancelRequest;
	Node *m_NearstGoal;

  bool m_staticObstacle;
  bool m_dynamicObstacle;
  bool m_dynamicObstacleEx;
  int m_agentCellSize;

  int m_bAutoUseDynamic;
  int m_nUnUseDynamicNodes;

public:
    void SetSpecParam(bool staticObstacle,bool dynamicObstacle,bool dynamicObstacleEx, int agentCellSize, int bAutoUseDynamic)
    {
        m_staticObstacle = staticObstacle;
        m_dynamicObstacle = dynamicObstacle;
        m_agentCellSize = agentCellSize;

		m_bAutoUseDynamic = bAutoUseDynamic;
        m_dynamicObstacleEx = dynamicObstacleEx;
    }
};

#endif