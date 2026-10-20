#include <test/test.h>


bool test_qbuild_platform_detector() {
	bool success = true;
	success &= test_qbuild_platform_detector_default();
	return success;
}

