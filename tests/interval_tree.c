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
#include "itree.h"

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

interval_t **make_intervals() {
  int data[] = { 10, 20, 30, 40, 50, 25 };
  
  interval_t** intervals = malloc ( 6 * sizeof *intervals );
  intervals[0] = interval_new ( 15, 20, &data[0], clone_data, destroy_data );
  intervals[1] = interval_new ( 10, 30, &data[1], clone_data, destroy_data );
  intervals[2] = interval_new ( 17, 19, &data[2], clone_data, destroy_data );
  intervals[3] = interval_new ( 5,  20, &data[3], clone_data, destroy_data );
  intervals[4] = interval_new ( 12, 15, &data[4], clone_data, destroy_data );
  intervals[5] = interval_new ( 30, 40, &data[5], clone_data, destroy_data );

  return intervals;
}

void destroy_intervals(interval_t **intervals) {
  for(int i=0; i<6; ++i)
    interval_delete ( intervals[i] );
  
  free ( intervals );
}

START_TEST(tree_creation)
{
  itree_t* tree = itree_new( clone_data, destroy_data );
  ck_assert ( tree );

  ck_assert_int_eq ( itree_size( tree ), 0 );

  itree_delete ( tree );
}
END_TEST

START_TEST(tree_indel)
{
  interval_t **intervals = make_intervals();
  itree_t* tree = itree_new( clone_data, destroy_data );
  
  for(int i=0; i<6; ++i)
    ck_assert( itree_insert ( tree, intervals[i] ) );
  ck_assert_int_eq ( itree_size ( tree ), 6 );

  for(int i=0; i<6; ++i) {
    /*
     * TODO: tests the edge cases, when interval equality test
     *       based on float comparison is not robust
     */
    ck_assert ( itree_remove ( tree, intervals[i] ) );
    ck_assert_int_eq ( itree_size ( tree ), 5-i );
  }
  
  itree_delete ( tree );

  /* tree is released but has made a copy of the original intervals */
  int data[] = { 10, 20, 30, 40, 50, 25 };
  for(int i=0; i<6; ++i) {
    ck_assert ( intervals[i] );
    ck_assert_int_eq ( get_data ( intervals[i]->data ), data[i] );
  }

  destroy_intervals( intervals );
}
END_TEST

START_TEST(tree_search)
{
  interval_t **intervals = make_intervals();
  itree_t* tree = itree_new( clone_data, destroy_data );
  
  for(int i=0; i<6; ++i)
    itree_insert ( tree, intervals[i] );

  int dummy = 10;
  interval_t *query = interval_new( 6., 7., &dummy, clone_data, destroy_data );
  interval_t *result = itree_find( tree, query );
  ck_assert ( result );
  ck_assert ( result->low == 5 );
  ck_assert ( result->high == 20 );

  query->low = 1.;
  query->high = 4.;
  result = itree_find ( tree, query );
  ck_assert ( !result );

  query->low = 18.;
  query->high = 25.;
  result = itree_find( tree, query );
  ck_assert ( result );
  ck_assert ( result->low == 15 );
  ck_assert ( result->high == 20 );

  query->low = 8;
  query->high = 11;
  ilist_t *results = itree_findall( tree, query );
  ck_assert( results );
  ck_assert_int_eq( ilist_size( results ), 2 );
  
  ilisttrav_t* trav = ilisttrav_new( results );
  const interval_t* item;
  for( item = ilisttrav_first( trav ); item!=NULL; item=ilisttrav_next( trav ) ) {
    ck_assert ( item );
    ck_assert ( item->low == 5 || item->low == 10 );
    ck_assert ( item->high == 20 || item->high == 30 );
  }
  ilisttrav_delete( trav );
  ilist_delete( results );
  
  interval_delete ( query );
  itree_delete ( tree );
  destroy_intervals( intervals );
}
END_TEST


static Suite *interval_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Interval Tree");

    tc_core = tcase_create("Core"); /* Core test case */
    tcase_add_test(tc_core, tree_creation);
    tcase_add_test(tc_core, tree_indel);
    tcase_add_test(tc_core, tree_search);
    
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
