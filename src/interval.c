/*
  Interval Tree library

  
*/
#include "interval.h"

#ifdef __cplusplus
#include <cstdlib>

using std::malloc;
using std::free;
using std::size_t;
#else
#include <stdlib.h>
#include <stdio.h>
#endif

#ifndef HEIGHT_LIMIT
#define HEIGHT_LIMIT 64
#endif

/* Note: doesn't own the interval, comes from the tree 
   which is responsible for deallocating the interval. */
typedef struct ilistnode {

  const interval_t* interval;
  struct ilistnode *next;

} ilistnode_t;
  
struct ilist {

  ilistnode_t *head, *tail; /* Dummy nodes */
  size_t      size;

};

struct ilisttrav {

  ilist_t     *list;               /* Paired list */
  ilistnode_t *it;                 /* Current node */

};

interval_t *interval_new ( float low, float high, void *data, dup_f dup, rel_f rel ) {

  interval_t *ri = (interval_t*) malloc ( sizeof *ri );

  if ( ri == NULL )
    return NULL;

  ri->low = low;
  ri->high = high;
  ri->dup = dup;
  ri->rel = rel;
  ri->data = ri->dup( data );
  
  return ri;
}

interval_t *interval_copy ( const interval_t *i ) {
  return interval_new ( i->low, i->high, i->data, i->dup, i->rel );
}

void interval_delete ( interval_t *i ) {
  if ( i != NULL ) {
    
    i->rel ( i->data );
    free ( i );
  }

}

int interval_overlap(const interval_t* i1, const interval_t* i2) {
  return i1->low <= i2->high && i2->low <= i1->high;
}

int interval_equal(const interval_t* i1, const interval_t* i2) {
  return i1->low == i2->low && i1->high == i2->high;
}

static ilistnode_t *ilistnode_new( const interval_t *i, ilistnode_t *next ) {

  ilistnode_t *node = (ilistnode_t*) malloc ( sizeof *node );

  if (node != NULL ) {
    node->interval = i; /* NOTE: doesn't own the interval, pointer aliasing */
    node->next = next;
  }

  return node;
}

/* 
   Destroy a single node, assuming it's been unlinked.
   Returns the next node specified by the link.
*/

ilistnode_t *ilistnode_delete(ilistnode_t* node) {
  ilistnode_t *next = NULL;

  if ( node != NULL ) {
    /* Save a reference to the next node 
       since we're about to destroy this one */
    next = node->next;

    free ( node );
  }

  return next;
}

ilist_t *ilist_new() {
  ilist_t *list = (ilist_t*) malloc ( sizeof *list);

  if ( list != NULL ) {
    ilistnode_t *tail = ilistnode_new(NULL, NULL);

    if ( tail == NULL ) {
      free( list );
      list = NULL;
    } else {
      list->tail = tail;
      list->head = ilistnode_new(NULL, list->tail);
      
      if ( list->head == NULL) {
	free ( list );
	list = NULL;
      }

      list->size = 0;

    }
    
  }

  return list;
}

void ilist_delete(ilist_t *list) {

  ilistnode_t *it = list->head;

  while ( it != list->tail ) {
    it = ilistnode_delete( it );
  }

  ilistnode_delete( it ); /* Delete tail */
}

size_t ilist_size(ilist_t *list) {
  return list->size;
}

static ilistnode_t *insert_before(ilist_t*, ilistnode_t*, interval_t*);

static ilistnode_t *insert_after(ilist_t *list, ilistnode_t *pos, interval_t *i) {
  ilistnode_t *node = NULL;

  if ( list != NULL && pos != NULL ) {

    if ( pos != list->tail ) {

      node = ilistnode_new( i, pos->next );

      if ( node != NULL ) {
	pos->next = node;
	++list->size;
      }
      
    } else
      node = insert_before ( list, pos, i );
  }

  return node;
}

static ilistnode_t *insert_before(ilist_t *list, ilistnode_t *pos, interval_t *i) {

  ilistnode_t *node = NULL;

  if ( list != NULL && pos != NULL ) {
    
    if ( pos != list->head ) {
      /* Find the previous node */
      ilistnode_t * it = list->head;

      while ( it->next != pos )
	it = it->next;

      /* Create a new node and set the new link */
      node = ilistnode_new( i, it->next );

      if ( node != NULL ) {
	it->next = node;
	++list->size;
      }
      
    } else
      node = insert_after( list, pos, i );
    
  }

  return node;
}

int ilist_append(ilist_t *list, interval_t *i) {

  ilistnode_t *node = insert_before ( list, list->tail, i);
  
  if ( node != NULL )
    return 1;

  return 0;
}

ilisttrav_t *ilisttrav_new( ilist_t *list ) {
  if ( list == NULL )
    return NULL;
  
  ilisttrav_t *trav = (ilisttrav_t*) malloc ( sizeof ( ilisttrav_t ) );

  if ( trav != NULL )
    trav->list = list;
  
  return trav;
}

void ilisttrav_delete ( ilisttrav_t *trav ) {
  free ( trav );
}

const interval_t *ilisttrav_first ( ilisttrav_t *trav ) {
  if ( trav->list == NULL )
    return NULL;
  
  trav->it = trav->list->head->next;

  return trav->it == NULL || trav->it == trav->list->tail ? NULL : trav->it->interval;
}

const interval_t  *ilisttrav_last ( ilisttrav_t *trav ) {
  if ( trav->list == NULL )
    return NULL;
  
  trav->it = trav->list->head;

  while ( trav->it->next != trav->list->tail )
    trav->it = trav->it->next;
  
  return trav->it == trav->list->head || trav->it == NULL ? NULL : trav->it->interval;
}

const interval_t  *ilisttrav_next ( ilisttrav_t *trav ) {
  if ( trav == NULL)
    return NULL;
  
  trav->it = trav->it->next;

  return trav->it == NULL || trav->it == trav->list->tail ? NULL : trav->it->interval;
}

/* Very inefficient, need a doubly linked list to properly support this */
const interval_t  *ilisttrav_prev ( ilisttrav_t *trav ) {
  if ( trav == NULL )
    return NULL;

  ilistnode_t *it = trav->list->head;

  while ( it->next != trav->it )
    it = it->next;

  trav->it = it;
  
  return trav->it == trav->list->head || trav->it == NULL ? NULL : trav->it->interval;
}
