#include <check_filter.h>


START_TEST(test_filter_null_pb_src)
{
    int arr[] = {0, 1, 2, 3};
    int *pb_dst, *pe_dst;

    int res = key(NULL, arr + 4, &pb_dst, &pe_dst);
    ck_assert_int_eq(res, ERR_PROCESS);
}
END_TEST


START_TEST(test_filter_null_pe_src)
{
    int arr[] = {0, 1, 2, 3};
    int *pb_dst, *pe_dst;

    int res = key(arr, NULL, &pb_dst, &pe_dst);
    ck_assert_int_eq(res, ERR_PROCESS);
}
END_TEST


START_TEST(test_filter_null_pb_dst)
{
    int *pe_dst;
    int arr[] = {0, 1, 2, 3};

    int res = key(arr, arr + 4, NULL, &pe_dst);
    ck_assert_int_eq(res, ERR_PROCESS);
}
END_TEST


START_TEST(test_filter_null_pe_dst)
{
    int *pb_dst;
    int arr[] = {0, 1, 2, 3};

    int res = key(arr, arr + 4, &pb_dst, NULL);
    ck_assert_int_eq(res, ERR_PROCESS);
}
END_TEST


START_TEST(test_filter_pb_src_gt_pe_src)
{
    int arr[] = {0, 1, 2, 3};
    int *pb_dst, *pe_dst;

    int res = key(arr + 4, arr, &pb_dst, &pe_dst);
    ck_assert_int_eq(res, ERR_PROCESS);
}
END_TEST


START_TEST(test_filter_some_remain)
{
    int arr[] = {1, 2, 3, 4};
    int arr_res[] = { 3, 4};
    int *pb_dst, *pe_dst;

    int res = key(arr, arr + 4, &pb_dst, &pe_dst);

    ck_assert_int_eq(res, OK);
    ck_assert_ptr_eq(pe_dst, pb_dst + 2);
    ck_assert_mem_eq(pb_dst, arr_res, 2 * sizeof(int));
    free(pb_dst);
}
END_TEST


START_TEST(test_filter_nothing_remain)
{
    int *pb_dst;
    int *pe_dst;
    int arr[] = {1, 1, 1, 1};

    int res = key(arr, arr + 4, &pb_dst, &pe_dst);

    ck_assert_int_eq(res, ERR_ARR_LEN);
}
END_TEST


Suite* filter_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("filter");

    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, test_filter_null_pb_src);
    tcase_add_test(tc_neg, test_filter_null_pe_src);
    tcase_add_test(tc_neg, test_filter_null_pb_dst);
    tcase_add_test(tc_neg, test_filter_null_pe_dst);
    tcase_add_test(tc_neg, test_filter_pb_src_gt_pe_src);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_filter_some_remain);
    tcase_add_test(tc_pos, test_filter_nothing_remain);
    suite_add_tcase(s, tc_pos);

    return s;
}