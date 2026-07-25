#include <test/test.h>

extern bool test_qbuild_project();

bool test_qbuild() {
	bool success = true;
	success &= test_qbuild_project();
	return success;
}

