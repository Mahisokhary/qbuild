#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_string_lower() {
	test_run_log();
	char upper[] = "ASDfdsg/%_+";
	char lower[] = "asdfdsg/%_+";

	bool success = true;
	qbuild_string_lower(upper);
	test(success, exit, strcmp(upper, lower) == 0);
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_string_format() {
	test_run_log();
	char *fmt = "my name is %s";
	char *fmt_param = "qoqnus";
	char *expected_res = "my name is qoqnus";
	char *res;

	bool success = true;
	res = qbuild_string_format(fmt, fmt_param);
	test(success, free, strcmp(expected_res, res) == 0);
free:
	free(res);
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_string() {
	bool success = true;
	success &= test_qbuild_string_lower();
	success &= test_qbuild_string_format();
	return success;
}

