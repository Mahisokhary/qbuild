#include <qbuild/qbuild.internal.h>
#ifdef __POSIX__
#include <sys/utsname.h>
#endif

char *qbuild_platform_host_name() {
#ifdef __POSIX__
	struct utsname s;
	uname(&s);
	qbuild_string_lower(s.sysname);
	return strdup(s.sysname);
#else
	return NULL;
#endif
}

