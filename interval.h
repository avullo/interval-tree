#ifndef _INTERVAL_H_
#define _INTERVAL_H_

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

/* Interval functions */
int interval_overlap(const interval_t*, const interval_t*);

#ifdef __cplusplus
}
#endif

#endif /* _INTERVAL_H_ */
