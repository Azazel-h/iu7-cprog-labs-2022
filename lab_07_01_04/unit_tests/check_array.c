#include "check_array.h"


START_TEST(test_allocate_int_array)
{
    int *pb = NULL, *pe = NULL;
    allocate_int_array(2, &pb, &pe);
    ck_assert_ptr_nonnull(pb);
    ck_assert_ptr_nonnull(pe);
    ck_assert_int_eq(pe - pb, 2);

    free(pb);
    pb = NULL;
    pe = NULL;
}
END_TEST


START_TEST(test_free_int_array)
{
    int *pb = NULL, *pe = NULL;
    pb = malloc(2 * sizeof(int));
    ck_assert_ptr_nonnull(pb);
    pe = pb + 2;

    free_int_array(&pb, &pe);
    ck_assert_ptr_null(pb);
    ck_assert_ptr_null(pe);
}
END_TEST


START_TEST(test_avg_array)
{
    int arr[] = {0, 1};
    int *pb = arr, *pe = arr + 2;
    ck_assert_double_eq(count_avg_array(pb, pe), 0.5);
}
END_TEST


Suite* array_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("array");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_allocate_int_array);
    tcase_add_test(tc_pos, test_avg_array);
    tcase_add_test(tc_pos, test_free_int_array);

    suite_add_tcase(s, tc_pos);
    return s;
}
