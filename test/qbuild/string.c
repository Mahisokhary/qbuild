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

bool test_qbuild_string_array_copy() {
	test_run_log();
	size_t len = 3;
	char *strings[] = { "1", "2", "3" };
	char *strings2[len];

	bool success = true;
	qbuild_string_array_copy(len, strings, strings2);
	for (int i = 0; i < len; i++)
		test(success, clean, strcmp(strings[i], strings2[i]) == 0);
clean:
	for (int i = 0; i < len; i++)
		free(strings2[i]);
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_string_array_dup() {
	test_run_log();
	size_t len = 3;
	char *strings[] = { "1", "2", "3" };
	char **strings2;

	bool success = true;
	test(success, exit, (strings2 = qbuild_string_array_dup(len, strings)));
	for (int i = 0; i < len; i++)
		test(success, clean, strcmp(strings[i], strings2[i]) == 0);
clean:
	for (int i = 0; i < len; i++)
		free(strings2[i]);
	free(strings2);
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_string() {
	bool success = true;
	success &= test_qbuild_string_lower();
	success &= test_qbuild_string_format();
	success &= test_qbuild_string_array_copy();
	success &= test_qbuild_string_array_dup();
	return success;
}

