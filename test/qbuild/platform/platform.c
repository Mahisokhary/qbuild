#include <test/test.h>
#include <qbuild/qbuild.internal.h>

extern bool test_qbuild_platform_detector();

bool test_qbuild_platform() {
	bool success = true;
	success &= test_qbuild_platform_detector();
	return success;
}

