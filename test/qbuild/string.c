#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_string_lower() {
	test_run_log("qbuild_string_lower");
	char upper[] = "ASDfdsg/%_+";
	char lower[] = "asdfdsg/%_+";

	bool success = true;
	qbuild_string_lower(upper);
	success &= strcmp(upper, lower) == 0;
	test_result_log(success);
	return success;
}

bool test_qbuild_string() {
	bool success = true;
	success &= test_qbuild_string_lower();
	return success;
}

