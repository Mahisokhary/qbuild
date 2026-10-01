#include <test/test.h>
#include <qbuild/qbuild.h>
#include <string.h>

bool test_qbuild_project_load() {
	test_run_log();
	qbuild_project_t p;

	bool success = true;
	test_run(success, exit, qbuild_project_load(&p, "example"));
	test(success, destroy, strcmp(qbuild_project_name(p), "qbuild-example") == 0);
	test(success, destroy, strcmp(qbuild_project_version(p), "1.0.0-beta") == 0);
destroy:
	test_run(success, exit, qbuild_project_destroy(p));
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_project() {
	bool success = true;
	success &= test_qbuild_project_load();
	return success;
}

