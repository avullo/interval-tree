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

static Suite *interval_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Interval");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, interval_creation);
    tcase_add_test(tc_core, interval_duplication);

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
