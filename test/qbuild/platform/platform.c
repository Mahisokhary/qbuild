#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_platform_host_name() {
	test_run_log();
	char *host = qbuild_platform_host_name();

	bool success = true;
#ifdef TEST_QBUILD_PLATFORM_HOST_NAME
	test(success, exit, strcmp(host, TEST_QBUILD_PLATFORM_HOST_NAME) == 0);
#endif
exit:
	free(host);
	test_result_log(success);
	return success;
}

bool test_qbuild_platform() {
	bool success = true;
	success &= test_qbuild_platform_host_name();
	return success;
}

