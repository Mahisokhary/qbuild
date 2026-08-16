#include <test/test.h>

extern bool test_qbuild_project();
extern bool test_qbuild_file();

bool test_qbuild() {
	bool success = true;
	success &= test_qbuild_project();
	success &= test_qbuild_file();
	return success;
}

