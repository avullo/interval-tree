#ifndef _INTERVAL_H_
#define _INTERVAL_H_

/*
  Interval Tree library

  Representing and operating an interval.

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
  void   *data;     /* User-defined content */
} interval_t;

/* Declarations for an interval list, opaque types */
typedef struct ilist ilist_t;
typedef struct ilisttrav ilisttrav_t;
  
/* Interval functions */
int interval_overlap(const interval_t*, const interval_t*);
int interval_equal(const interval_t*, const interval_t*);

/* Interval list functions */
ilist_t     *ilist_new();
void        ilist_delete(ilist_t*);
size_t      ilist_size(ilist_t*);
int         ilist_append(ilist_t*, interval_t*);

/* Interval list traversal functions */
ilisttrav_t *ilisttnew ( void );
void        ilistdelete ( ilisttrav_t *trav );
interval_t  *ilistfirst ( ilisttrav_t *trav, ilist_t *list );
interval_t  *ilistlast ( ilisttrav_t *trav, ilist_t *list );
interval_t  *ilistnext ( ilisttrav_t *trav );
interval_t  *ilisttprev ( ilisttrav_t *trav );

#ifdef __cplusplus
}
#endif

#endif /* _INTERVAL_H_ */
