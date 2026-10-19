#include <test/test.h>

extern bool test_qbuild_project();
extern bool test_qbuild_file();
extern bool test_qbuild_string();
extern bool test_qbuild_context();
extern bool test_qbuild_platform();
extern bool test_qbuild_module();

bool test_qbuild() {
	bool success = true;
	success &= test_qbuild_project();
	success &= test_qbuild_file();
	success &= test_qbuild_string();
	success &= test_qbuild_context();
	success &= test_qbuild_platform();
	success &= test_qbuild_module();
	return success;
}

