#ifndef _qbuild_qbuild_internal_h_
#define _qbuild_qbuild_internal_h_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <qbuild/qbuild.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Runs a qbuild function takes qbuild context, function and function arguments as arguments
 * And log failure
 */
#define qbuild_runc(c, call, ...) do { \
	qbuild_result_t res = call(__VA_ARGS__); \
	if (res != QBUILD_RESULT_OK) { \
		log_errorf(c->logman, "Function " #call " failed with result: %s", qbuild_result_string(res)); \
		return res; \
	} \
	} while (0);

#define qbuild_run(call) do { \
	qbuild_result_t res = call; \
	if (res != QBUILD_RESULT_OK) return res; \
	} while (0);

#define qbuild_debug() (getenv("QBUILD_DEBUG"))

#ifdef __cplusplus
}
#endif

#include <qbuild/posix.internal.h>
#include <qbuild/qson.internal.h>
#include <qbuild/qstruct/qstruct.internal.h>
#include <qbuild/qolman/qolman.internal.h>
#include <qbuild/file/file.internal.h>
#include <qbuild/string/string.internal.h>
#include <qbuild/platform/platform.internal.h>
#include <qbuild/project/project.internal.h>
#include <qbuild/context/context.internal.h>

#endif

