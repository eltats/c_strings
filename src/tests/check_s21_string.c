#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"
// #include "s21_sprintf_tests/s21_string_test.c"
#include "s21_sprintf_tests/test_s21_sprintf.c"
#include "test_insert.c"
#include "test_memchr.c"
#include "test_memcmp.c"
#include "test_memcpy.c"
#include "test_memmove.c"
#include "test_memset.c"
#include "test_strcat.c"
#include "test_strchr.c"
#include "test_strcmp.c"
#include "test_strcpy.c"
#include "test_strcspn.c"
#include "test_strerror.c"
#include "test_strlen.c"
#include "test_strncat.c"
#include "test_strncmp.c"
#include "test_strncpy.c"
#include "test_strpbrk.c"
#include "test_strrchr.c"
#include "test_strspn.c"
#include "test_strstr.c"
#include "test_strtok.c"
#include "test_to_lower.c"
#include "test_to_upper.c"
#include "test_trim.c"

Suite *s21_string_suite(void) {
    Suite *s;
    TCase *tc_core;
    TCase *tc_sprintf;

    s = suite_create("S21_string");

    tc_core = tcase_create("Core");

    // // тут добавляем новые тесты по образу и подобию
    tcase_add_test(tc_core, test_memchr);
    tcase_add_test(tc_core, test_memcmp);
    tcase_add_test(tc_core, test_memcpy);
    tcase_add_test(tc_core, test_memmove);
    tcase_add_test(tc_core, test_memset);
    tcase_add_test(tc_core, test_strcat);
    tcase_add_test(tc_core, test_strchr);
    tcase_add_test(tc_core, test_strcmp);
    tcase_add_test(tc_core, test_strcpy);
    tcase_add_test(tc_core, test_strcspn);
    tcase_add_test(tc_core, test_strerror);
    tcase_add_test(tc_core, test_strlen);
    tcase_add_test(tc_core, test_strncat);
    tcase_add_test(tc_core, test_strncmp);
    tcase_add_test(tc_core, test_strncpy);
    tcase_add_test(tc_core, test_strpbrk);
    tcase_add_test(tc_core, test_strrchr);
    tcase_add_test(tc_core, test_strspn);
    tcase_add_test(tc_core, test_strstr);
    tcase_add_test(tc_core, test_strtok);
    tcase_add_test(tc_core, test_insert);
    tcase_add_test(tc_core, test_to_lower);
    tcase_add_test(tc_core, test_to_upper);
    tcase_add_test(tc_core, test_trim);
    suite_add_tcase(s, tc_core);

    ////////////////////////////// sprintf //////////////////////////////
    tc_sprintf = tcase_create("Sprintf_core");

    tcase_add_test(tc_sprintf, s21_sprintf_hard_d);
    tcase_add_test(tc_sprintf, s21_sprintf_d);
    tcase_add_test(tc_sprintf, s21_sprintf_p);
    tcase_add_test(tc_sprintf, s21_sprintf_u);
    tcase_add_test(tc_sprintf, s21_sprintf_f);

    tcase_add_test(tc_sprintf, s21_sprintf_c);

    tcase_add_test(tc_sprintf, s21_sprintf_cs);

    tcase_add_test(tc_sprintf, s21_sprintf_l);
    tcase_add_test(tc_sprintf, s21_sprintf_h);

    /////
    tcase_add_test(tc_sprintf, s21_sprintf_s);

    tcase_add_test(tc_sprintf, s21_sprintf_long);

    tcase_add_test(tc_sprintf, s21_sprintf_hd);
    tcase_add_test(tc_sprintf, s21_sprintf_diu_with_str);

    tcase_add_test(tc_sprintf, s21_sprintf_f_with_str);

    tcase_add_test(tc_sprintf, s21_sprintf_empty);
    tcase_add_test(tc_sprintf, s21_v3_hard);

    suite_add_tcase(s, tc_sprintf);
    ////////////////////////////// sprintf //////////////////////////////

    return s;
}

int main(void) {
    // int number_failed;
    Suite *s;
    SRunner *sr;

    s = s21_string_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    // number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    // return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
    return 0;
}
