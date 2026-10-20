#ifndef _qbuild_module_module_h_
#define _qbuild_module_module_h_


#ifdef __cplusplus
extern "C" {
#endif

/*
 * A qbuild module
 */
typedef const struct qbuild_module *qbuild_module_t;

/*
 * Loads a module in given context
 */
qbuild_result_t qbuild_module_load(qbuild_context_t c, qbuild_module_t m);

#ifdef __cplusplus
}
#endif

#endif

