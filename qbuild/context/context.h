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

#ifdef __cplusplus
}
#endif

#endif

