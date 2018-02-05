#ifndef INTERVAL_TREE_H
#define INTERVAL_TREE_H

/*
  Interval Tree library

*/
#ifdef __cplusplus
#include <cstddef>

using std::size_t;

extern "C" {
#else
#include <stddef.h>
#endif

/* Opaque types */
typedef struct interval interval_t;
typedef struct itree itree_t;
typedef struct itreetrav itreetrav_t;

/* User-defined interval data item handling */
typedef void *(*dup_f) ( void* p );
typedef void  (*rel_f) ( void* p );

/* Interval tree functions */
itree_t *itree_new ( dup_f dup, rel_f rel );
void     itree_delete ( itree_t *tree );
void    *itree_find ( itree_t *tree, interval_t *interval );
int      itree_insert ( itree_t *tree, interval_t *interval );
int      itree_erase ( itree_t *tree, interval_t *interval );
size_t   itree_size ( itree_t *tree );

/* Tree traversal functions */
itreetrav_t *itreetnew ( void );
void     itreetdelete ( itreetrav_t *trav );
void    *itreetfirst ( itreetrav_t *trav, itree_t *tree );
void    *itreetlast ( itreetrav_t *trav, itree_t *tree );
void    *itreetnext ( itreetrav_t *trav );
void    *itreetprev ( itreetrav_t *trav );

#ifdef __cplusplus
}
#endif

#endif /* INTERVAL_TREE_H */
