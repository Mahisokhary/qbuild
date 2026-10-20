#ifndef _qbuild_platform_detector_detector_h_
#define _qbuild_platform_detector_detector_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Detects host platform
 */
typedef qbuild_result_t (*qbuild_platform_detector_t)(qbuild_context_t c, char **name);

#ifdef __cplusplus
}
#endif

#include "default.h"

#endif

