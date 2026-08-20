#include <test/test.h>

extern bool test_qbuild_project();
extern bool test_qbuild_file();
extern bool test_qbuild_context();
extern bool test_qbuild_platform();

bool test_qbuild() {
	bool success = true;
	success &= test_qbuild_project();
	success &= test_qbuild_file();
	success &= test_qbuild_context();
	success &= test_qbuild_platform();
	return success;
}

