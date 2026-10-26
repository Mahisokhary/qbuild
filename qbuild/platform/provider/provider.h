#ifndef _qbuild_platform_provider_provider_h_
#define _qbuild_platform_provider_provider_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Provides platforms
 */
typedef qbuild_result_t (*qbuild_platform_provider_t)(qbuild_context_t c, qbuild_platform_context_t pc, const char *name);

#ifdef __cplusplus
}
#endif


#endif

