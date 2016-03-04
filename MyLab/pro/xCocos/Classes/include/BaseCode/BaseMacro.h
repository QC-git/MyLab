// -*- C++ -*-

//=============================================================================
/**
*  @file    BaseMacro.h
*
*  $Id: BaseMacro.h  2009-01-13 14:33:41 $
*
*  @author chenhengxiu
*  note: 
*/
//=============================================================================

#ifndef _TQ_BASEMACRO_H_
#define _TQ_BASEMACRO_H_

#define     NAMESPACE_CLASS(ns,c)   namespace ns{class c;}
#define		NAMESPACE_BEGIN(x)		namespace x{
#define		NAMESPACE_END(x)		}

#ifndef _FARQ	/* specify standard memory model */
#define _FARQ
#define _PDFT	ptrdiff_t
#define _SIZT	size_t
#endif

#if defined (__TQ_INLINE__)
#  define TQ_INLINE inline
#else
#  define TQ_INLINE
#endif /* __TQ_INLINE__ */

#ifndef ENOMEM
#define ENOMEM 12
#endif

#define  ALIGNMENT				8   /* must be 2^N */
#define  ALIGNMENT_MASK			(ALIGNMENT - 1)
#define  ROUNDUP(x)				(((x) + ALIGNMENT_MASK) &  ~ALIGNMENT_MASK)

#define  ALIGNMENT_1K				1024   /* must be 1024^N */
#define  ALIGNMENT_MASK_1K			(ALIGNMENT_1K - 1)
#define  ROUNDUP_1K(x)				(((x) + ALIGNMENT_MASK_1K) &  ~ALIGNMENT_MASK_1K)
 
# define TQ_ALLOCATOR_RETURN(POINTER,ALLOCATOR,RET_VAL) \
	do { POINTER = ALLOCATOR; \
	if (POINTER == 0) { errno = ENOMEM; return RET_VAL; } \
	} while (0)

# define TQ_ALLOCATOR(POINTER,ALLOCATOR) \
	do { POINTER = ALLOCATOR; \
	if (POINTER == 0) { errno = ENOMEM; return; } \
	} while (0)

# define TQ_ALLOCATOR_NORETURN(POINTER,ALLOCATOR) \
	do { POINTER = ALLOCATOR; \
	if (POINTER == 0) { errno = ENOMEM; } \
	} while (0)

# define TQ_NEW_MALLOC_RETURN(POINTER,ALLOCATOR,CONSTRUCTOR,RET_VAL) \
	do { POINTER = ALLOCATOR; \
	if (POINTER == 0) { errno = ENOMEM; return RET_VAL;} \
	else { (void) new (POINTER) CONSTRUCTOR; } \
	} while (0)

# define TQ_NEW_MALLOC(POINTER,ALLOCATOR,CONSTRUCTOR) \
	do { POINTER = ALLOCATOR; \
	if (POINTER == 0) { errno = ENOMEM; return;} \
	else { (void) new (POINTER) CONSTRUCTOR; } \
	} while (0)

# define TQ_NEW_MALLOC_NORETURN(POINTER,ALLOCATOR,CONSTRUCTOR) \
	do { POINTER = ALLOCATOR; \
	if (POINTER == 0) { errno = ENOMEM;} \
	else { (void) new (POINTER) CONSTRUCTOR; } \
	} while (0)


# define TQ_DES_FREE_TEMPLATE(POINTER,DEALLOCATOR,T_CLASS,T_PARAMETER) \
	do { \
		if (POINTER) \
		{ \
			POINTER->T_CLASS T_PARAMETER::~T_CLASS (); \
			DEALLOCATOR (POINTER); \
		} \
	} \
    while (0)

#endif	//_TQ_BASEMACRO_H_



