#ifndef _qbuild_context_context_h_
#define _qbuild_context_context_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pointer to the actual context
 */
typedef struct qbuild_context* qbuild_context_t;

/*
 * Create a qbuild context
 */
qbuild_result_t qbuild_context_create(qbuild_context_t *ctx);

/*
 * Destroy the context
 */
qbuild_result_t qbuild_context_destroy(qbuild_context_t ctx);

/*
 * Returns context config dirs
 */
char** qbuild_context_config_dirs(qbuild_context_t c, size_t *length);

#ifdef __cplusplus
}
#endif

#endif

