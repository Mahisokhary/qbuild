#ifndef _qbuild_platform_provider_config_h_
#define _qbuild_platform_provider_config_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Provides platforms from json configs
 */
qbuild_result_t qbuild_platform_provider_config(qbuild_context_t c, qbuild_platform_context_t pc, const char *name);

#ifdef __cplusplus
}
#endif

#endif

