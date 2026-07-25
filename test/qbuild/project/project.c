#include <test/test.h>
#include <qbuild/qbuild.h>
#include <string.h>

bool test_qbuild_project_load() {
	test_run_log("qbuild_project_load");
	qbuild_project_t p;

	bool success = true;
	success &= qbuild_project_load(&p, "example") == QBUILD_RESULT_OK;
	success &= strcmp(qbuild_project_name(p), "qbuild-example") == 0;
	success &= strcmp(qbuild_project_version(p), "1.0.0-beta") == 0;
	success &= qbuild_project_destroy(p) == QBUILD_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qbuild_project() {
	bool success = true;
	success &= test_qbuild_project_load();
	return success;
}

