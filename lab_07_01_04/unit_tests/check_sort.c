#include <check_sort.h>


START_TEST(test_sort_for_descending_int)
{
    int arr[] = {4, 3, 2, 1};
    int arr_res[] = { 1, 2, 3, 4};

    mysort(arr, 4, sizeof(int), int_cmp);
    ck_assert_mem_eq(arr, arr_res, 4 * sizeof(int));
}
END_TEST


START_TEST(test_sort_for_ascending_int)
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_res[] = { 1, 2, 3, 4, 5};

    mysort(arr, 5, sizeof(int), int_cmp);
    ck_assert_mem_eq(arr, arr_res, 5 * sizeof(int));
}
END_TEST


START_TEST(test_sort_for_different_int)
{
    int arr[] = {4, 8, 8, -1, 20, -80, -90};
    int arr_res[] = {-90, -80, -1, 4, 8, 8, 20};

    mysort(arr, 7, sizeof(int), int_cmp);
    ck_assert_mem_eq(arr, arr_res, 7 * sizeof(int));
}
END_TEST


static int double_cmp(const void *l, const void *r)
{
    double *l_a = (double *) l;
    double *r_b = (double *) r;
    return (*l_a > *r_b) ? 1 : -1;
}


START_TEST(test_sort_for_descending_double)
{
    double arr[] = {4.1, 3.1, 2.1, 1.1};
    double arr_res[] = { 1.1, 2.1, 3.1, 4.1};

    mysort(arr, 4, sizeof(double), double_cmp);
    ck_assert_mem_eq(arr, arr_res, 4 * sizeof(double));
}
END_TEST


START_TEST(test_sort_for_ascending_double)
{
    double arr[] = {1.1, 2.1, 3.1, 4.1, 5.1};
    double arr_res[] = {1.1, 2.1, 3.1, 4.1, 5.1};

    mysort(arr, 5, sizeof(double), double_cmp);
    ck_assert_mem_eq(arr, arr_res, 5 * sizeof(double));
}
END_TEST


START_TEST(test_sort_for_different_double)
{
    double arr[] = {4.1, 8.11, 8.11, -1.111, 20.111, -80.1111, -90.11111};
    double arr_res[] = {-90.11111, -80.1111, -1.111, 4.1, 8.11, 8.11, 20.111};

    mysort(arr, 7, sizeof(double), double_cmp);
    ck_assert_mem_eq(arr, arr_res, 7 * sizeof(double));
}
END_TEST


static int char_cmp(const void *l, const void *r)
{
    char *l_a = (char *) l;
    char *r_b = (char *) r;
    return strcmp(l_a, r_b);
}


START_TEST(test_sort_for_descending_char)
{
    double arr[] = {'d', 'c', 'b', 'a'};
    double arr_res[] = { 'a', 'b', 'c', 'd'};

    mysort(arr, 4, sizeof(char), char_cmp);
    ck_assert_mem_eq(arr, arr_res, 4 * sizeof(char));
}
END_TEST


START_TEST(test_sort_for_ascending_char)
{
    double arr[] = {'a', 'b', 'c', 'd', 'e'};
    double arr_res[] = { 'a', 'b', 'c', 'd', 'e'};

    mysort(arr, 5, sizeof(char), char_cmp);
    ck_assert_mem_eq(arr, arr_res, 5 * sizeof(char));
}
END_TEST


START_TEST(test_sort_for_different_char)
{
    double arr[] = {'a', 'f', 'g', 'h', 'n', 'k', 'b', 'c'};
    double arr_res[] = { 'a', 'b', 'c', 'f', 'g', 'h', 'k', 'n'};

    mysort(arr, 5, sizeof(char), char_cmp);
    ck_assert_mem_eq(arr, arr_res, 5 * sizeof(char));
}
END_TEST


Suite* sort_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort");
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, test_sort_for_descending_int);
    tcase_add_test(tc_pos, test_sort_for_ascending_int);
    tcase_add_test(tc_pos, test_sort_for_different_int);
    tcase_add_test(tc_pos, test_sort_for_descending_double);
    tcase_add_test(tc_pos, test_sort_for_ascending_double);
    tcase_add_test(tc_pos, test_sort_for_different_double);
    tcase_add_test(tc_pos, test_sort_for_descending_char);
    tcase_add_test(tc_pos, test_sort_for_ascending_char);
    tcase_add_test(tc_pos, test_sort_for_different_char);
    suite_add_tcase(s, tc_pos);
    return s;
}