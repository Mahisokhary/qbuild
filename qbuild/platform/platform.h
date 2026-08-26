#ifndef _qbuild_platform_platform_h_
#define _qbuild_platform_platform_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pointer to actual platform
 */
typedef struct qbuild_platform *qbuild_platform_t;

/*
 * Detects name of host platform
 */
char *qbuild_platform_host_name();

#ifdef __cplusplus
}
#endif

#endif

