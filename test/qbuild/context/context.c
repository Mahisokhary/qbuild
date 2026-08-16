#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_context_create_destroy() {
	test_run_log("qbuild_context_create_destroy");
	qbuild_context_t ctx;

	bool success = 1;
	success &= qbuild_context_create(&ctx) == QBUILD_RESULT_OK;
	success &= qbuild_context_destroy(ctx) == QBUILD_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qbuild_context() {
	bool success = true;
	success &= test_qbuild_context_create_destroy();
	return success;
}

