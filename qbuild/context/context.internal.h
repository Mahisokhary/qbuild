#ifndef _qbuild_context_context_internal_h_
#define _qbuild_context_context_internal_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Qbuild Context
 */
struct qbuild_context {
	size_t config_dirs_length;
	char **config_dirs;
	struct qbuild_platform_context platform;
};

#ifdef __cplusplus
}
#endif

#endif

