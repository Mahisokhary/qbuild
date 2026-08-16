#include <test/test.h>

extern bool test_qbuild_project();
extern bool test_qbuild_file();
extern bool test_qbuild_context();

bool test_qbuild() {
	bool success = true;
	success &= test_qbuild_project();
	success &= test_qbuild_file();
	success &= test_qbuild_context();
	return success;
}

