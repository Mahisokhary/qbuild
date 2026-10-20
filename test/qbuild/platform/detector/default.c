#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_platform_detector_default() {
	test_run_log();
	char *host;

	bool success = true;
	test_run(success, exit, qbuild_platform_detector_default(NULL, &host));
#ifdef TEST_QBUILD_PLATFORM_HOST_NAME
	test(success, free, strcmp(host, TEST_QBUILD_PLATFORM_HOST_NAME) == 0);
#endif
free:
	free(host);
exit:
	test_result_log(success);
	return success;
}

