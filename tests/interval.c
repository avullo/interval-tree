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
#include "interval.h"

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

START_TEST(interval_creation)
{
  int dummy = 10;
  interval_t *i = interval_new ( 10, 20, &dummy, clone_data, destroy_data );
  
  ck_assert ( i );
  ck_assert_int_eq ( i->low, 10 );
  ck_assert_int_eq ( i->high, 20 );
  ck_assert_int_eq ( get_data ( i->data ), 10 );
  
  interval_delete( i );
  
}
END_TEST

START_TEST(interval_duplication)
{
  int dummy = 10;
  interval_t *i = interval_new ( 10, 20, &dummy, clone_data, destroy_data );
  interval_t *icopy = interval_copy ( i );
  
  ck_assert ( icopy );
  ck_assert_ptr_ne ( i, icopy );
  ck_assert_ptr_ne ( i->data, icopy->data );
  ck_assert_int_eq ( icopy->low, 10 );
  ck_assert_int_eq ( icopy->high, 20 );
  ck_assert_int_eq ( get_data ( icopy->data ), 10 );
    
  interval_delete( i );
  interval_delete( icopy );
  
}
END_TEST

START_TEST(interval_comparison)
{
  /* int dummy = 10; */
  /* interval_t *ints[] = { */
  /*   interval_new ( 10, 20, &dummy, clone_data, destroy_data ) */
  /* }; */
  /* interval_t *icopy = interval_copy ( i ); */
  
  /* ck_assert ( icopy ); */
  /* ck_assert_ptr_ne ( i, icopy ); */
  /* ck_assert_ptr_ne ( i->data, icopy->data ); */
  /* ck_assert_int_eq ( icopy->low, 10 ); */
  /* ck_assert_int_eq ( icopy->high, 20 ); */
  /* ck_assert_int_eq ( get_data ( icopy->data ), 10 ); */
    
  /* interval_delete( i ); */
  /* interval_delete( icopy ); */
  
}
END_TEST


static Suite *interval_suite(void) {
    Suite *s;
    TCase *tc_core, *tc_iops;

    s = suite_create("Interval");

    tc_core = tcase_create("Core"); /* Core test case */
    tc_iops = tcase_create("Operations");
    
    tcase_add_test(tc_core, interval_creation);
    tcase_add_test(tc_core, interval_duplication);
    tcase_add_test(tc_iops, interval_comparison);
    
    suite_add_tcase(s, tc_core);
    suite_add_tcase(s, tc_iops);
    
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
