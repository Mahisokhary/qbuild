#ifndef _qbuild_platform_platform_h_
#define _qbuild_platform_platform_h_

#ifdef __cplusplus
extern "C" {
#endif

#define QBUILD_PLATFORM_MODULE_NAME "qbuild.platform"

typedef struct qbuild_platform_context *qbuild_platform_context_t;

/*
 * Pointer to actual platform
 */
typedef struct qbuild_platform *qbuild_platform_t;

/*
 * Returns platform module
 */
qbuild_module_t qbuild_platform_module();

/*
 * Checks if platform is registered in the context
 */
bool qbuild_platform_has(qbuild_platform_context_t pc, const char *name);

/*
 * Registers platform with given properties in the context
 */
qbuild_result_t qbuild_platform_register(qbuild_platform_context_t pc, const char *name, size_t parents_length, const qbuild_platform_t *parents);

/*
 * Loads platform with given name in context
 */
qbuild_result_t qbuild_platform_load(qbuild_platform_context_t pc, const char *name);

/*
 * Fetches platform with given name in context (loads the platform if not loaded)
 */
qbuild_result_t qbuild_platform_fetch(qbuild_platform_context_t pc, const char *name, qbuild_platform_t *p);

#ifdef __cplusplus
}
#endif

#include "detector/detector.h"
#include "provider/provider.h"

#endif

