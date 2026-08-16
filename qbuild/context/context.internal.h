#ifndef _qbuild_context_context_internal_h_
#define _qbuild_context_context_internal_h_

#include <qbuild/qbuild.internal.h>
#include <qbuild/context/context.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Qbuild Context
 */
struct qbuild_context {
	size_t config_dirs_length;
	char **config_dirs;
};

#ifdef __cplusplus
}
#endif

#endif

