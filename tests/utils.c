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
#include "utils.h"

const float epsilon = 0.00001f;

START_TEST(small_positive_random)
{
  for(int i=0; i<10; ++i) {
    int n = rnd01();
    ck_assert(n >= 0 && n <= 1.0);
  }
}
END_TEST

START_TEST(small_random)
{
  for(int i=0; i<10; ++i) {
    int n = nrnd01();
    ck_assert(n >= -1.0 && n <= 1.0);
  }
}
END_TEST

/* START_TEST(big) */
/* { */

/*   ck_assert(nearly_equal(1e6, 11e5, epsilon)); */
/*   ck_assert(nearly_equal(11e5, 1e6, epsilon)); */
/*   ck_assert(!nearly_equal(1e4, 11e3, epsilon)); */
/*   ck_assert(!nearly_equal(11e3, 1e4, epsilon)); */
  
/* } */
/* END_TEST */

/* START_TEST(big_neg) */
/* { */
  
/* } */
/* END_TEST */

static Suite *utils_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Utils");

    tc_core = tcase_create("Core"); /* Core test case */
        
    tcase_add_test(tc_core, small_positive_random);
    tcase_add_test(tc_core, small_random);
        
    suite_add_tcase(s, tc_core);
        
    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = utils_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
