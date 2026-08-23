#ifndef _qbuild_platform_platform_internal_h_
#define _qbuild_platform_platform_internal_h_

#include <qbuild/qbuild.internal.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Platform
 */
struct qbuild_platform {
	char *name;
	size_t parents_length;
	struct qbuild_platform *parents[];
};

#ifdef __cplusplus
}
#endif

#endif

