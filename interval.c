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

int interval_overlap(const interval_t* i1, const interval_t* i2) {
  return i1->low <= i2->high && i2->low <= i1->high;
}
