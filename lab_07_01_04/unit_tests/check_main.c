#include <stdlib.h>
#include <check.h>
#include "check_array.h"
#include "check_filter.h"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = array_suite();
    runner = srunner_create(s);
    srunner_add_suite(runner, filter_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
