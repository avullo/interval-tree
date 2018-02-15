/*
 * Libitree: an interval tree library in C 
 *
 * Copyright (C) 2018 Alessandro Vullo 
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <check.h>
#include <stdlib.h>
#include "interval_list.h"

/* clone an integer */
void* clone_data ( void *p ) {
  int* c = (int*) malloc ( sizeof(int) );
  *c = *(int*)p;
  
  return c;
}

/* destroy an integer */
void destroy_data ( void *p ) {
  free(p);
}

int get_data ( void *p ) {
  return *(int*)p;
}

START_TEST(interval_list)
{
  ilist_t* list = ilist_new();
  ck_assert( list );
  
  interval_t* intervals[6];
  for(int i=1; i<=6; ++i) {
    intervals[i-1] = interval_new ( i*10, (i+1)*10, &i, clone_data, destroy_data );
    ck_assert( ilist_append( list, intervals[i-1]) );
  }

  ck_assert_int_eq ( ilist_size ( list ), 6 );
  
  ilisttrav_t* trav = ilisttrav_new( list );
  ck_assert( trav );
  
  const interval_t* item;
  int i = 1;
  for(item = ilisttrav_first(trav); item!=NULL; item=ilisttrav_next(trav), ++i) {
    ck_assert ( item );
    ck_assert_int_eq ( item->low, i*10 );
    ck_assert_int_eq ( item->high, (i+1)*10 );
    ck_assert_int_eq ( get_data ( item->data ), i );
  }
  
  for(i=6, item = ilisttrav_last(trav); item!=NULL; item=ilisttrav_prev(trav), --i) {
    ck_assert ( item );
    ck_assert_int_eq ( item->low, i*10 );
    ck_assert_int_eq ( item->high, (i+1)*10 );
    ck_assert_int_eq ( get_data ( item->data ), i );    
  }
  
  ilisttrav_delete( trav );
  ilist_delete( list );

  for(i=0; i<6; ++i)
    interval_delete( intervals[i] );

}
END_TEST

static Suite *interval_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Interval List");

    tc_core = tcase_create("Core"); /* Core test case */
    tcase_add_test(tc_core, interval_list);
    
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = interval_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
