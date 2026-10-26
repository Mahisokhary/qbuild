#ifndef _qbuild_platform_platform_h_
#define _qbuild_platform_platform_h_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct qbuild_platform_context *qbuild_platform_context_t;

/*
 * Pointer to actual platform
 */
typedef struct qbuild_platform *qbuild_platform_t;

#ifdef __cplusplus
}
#endif

#include "detector/detector.h"
#include "provider/provider.h"

#endif

