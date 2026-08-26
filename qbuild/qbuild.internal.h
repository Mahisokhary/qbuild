#ifndef _qbuild_qbuild_internal_h_
#define _qbuild_qbuild_internal_h_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <qbuild/qbuild.h>

#ifdef __cplusplus
extern "C" {
#endif

#define qbuild_run(call) do { \
	qbuild_result_t res = call; \
	if (res != QBUILD_RESULT_OK) return res; \
	} while (0);

#ifdef __cplusplus
}
#endif

#include <qbuild/posix.internal.h>
#include <qbuild/qson.internal.h>
#include <qbuild/file/file.internal.h>
#include <qbuild/string/string.internal.h>
#include <qbuild/context/context.internal.h>
#include <qbuild/platform/platform.internal.h>
#include <qbuild/project/project.internal.h>

#endif

