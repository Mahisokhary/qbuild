#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_platform_module() {
	test_run_log();
	qbuild_context_t ctx;
	char *config;

	bool success = 1;
	test_run(success, exit, qbuild_context_create(&ctx));
	test_run(success, destroy, qbuild_module_load(ctx, qbuild_platform_module()));
destroy:
	test_run(success, exit, qbuild_context_destroy(ctx));
exit:
	test_result_log(success);
	return success;
}

extern bool test_qbuild_platform_detector();

bool test_qbuild_platform() {
	bool success = true;
	success &= test_qbuild_platform_detector();
	success &= test_qbuild_platform_module();
	return success;
}

