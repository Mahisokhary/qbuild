#include <qbuild/qbuild.internal.h>
#ifdef __POSIX__
#include <sys/utsname.h>
#endif

qbuild_result_t qbuild_platform_detector_default(qbuild_context_t c, char **name) {
#ifdef __POSIX__
	struct utsname s;
	uname(&s);
	qbuild_string_lower(s.sysname);
	*name = strdup(s.sysname);
	return QBUILD_RESULT_OK;
#else
	return QBUILD_RESULT_PLATFORM_DETECTION_FAILED;
#endif
}

