#ifndef INTERVAL_TREE_H
#define INTERVAL_TREE_H

/*
  Interval Tree library

  This is an adaptation of the AVL balanced tree C library
  created by Julienne Walker which can be found here:

  http://www.eternallyconfuzzled.com/Libraries.aspx

*/
#ifdef __cplusplus
#include <cstddef>

using std::size_t;

extern "C" {
#else
#include <stddef.h>
#endif

typedef struct interval {
  float  low, high; /* Interval boundaries, inclusive */
  void  *data;      /* User-defined content */
} interval_t;

/* Opaque types */
typedef struct itree itree_t;
typedef struct itreetrav itreetrav_t;

/* User-defined interval data item handling */
typedef void *(*dup_f) ( void* p );
typedef void  (*rel_f) ( void* p );

/* Interval tree functions */
itree_t *itree_new ( dup_f dup, rel_f rel );
void     itree_delete ( itree_t *tree );
  // void    *itree_find ( itree_t *tree, interval_t *interval );
int      itree_insert ( itree_t *tree, interval_t *interval );
  // int      itree_erase ( itree_t *tree, interval_t *interval );
size_t   itree_size ( itree_t *tree );

/* Tree traversal functions */
itreetrav_t *itreetnew ( void );
void     itreetdelete ( itreetrav_t *trav );
interval_t    *itreetfirst ( itreetrav_t *trav, itree_t *tree );
interval_t    *itreetlast ( itreetrav_t *trav, itree_t *tree );
interval_t    *itreetnext ( itreetrav_t *trav );
interval_t    *itreetprev ( itreetrav_t *trav );

#ifdef __cplusplus
}
#endif

#endif /* INTERVAL_TREE_H */
