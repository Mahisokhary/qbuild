/*
 * QBuild internal helper for qolman
 */

#ifndef _qbuild_qolman_internal_h_
#define _qbuild_qolman_internal_h_

#include <qolman/qolman.h>

#ifdef __cplusplus
extern "C" {
#endif

#define qolman_run(call) if (call != QOLMAN_RESULT_OK) return QBUILD_RESULT_LOGGING_FAILED;

#define log_trace(m, label, description) qolman_run(qolman_manager_handle_trace(m, 0, __func__, label, description))
#define log_debug(m, label, description) qolman_run(qolman_manager_handle_debug(m, 0, __func__, label, description))
#define log_info(m, label, description) qolman_run(qolman_manager_handle_info(m, 0, __func__, label, description))
#define log_warning(m, label, description) qolman_run(qolman_manager_handle_warning(m, 0, __func__, label, description))
#define log_error(m, label, description) qolman_run(qolman_manager_handle_error(m, 0, __func__, label, description))

#define logf(m, importance, label, ...) do { \
		char *formatted = qbuild_string_format(label, __VA_ARGS__); \
		qolman_run(qolman_manager_handle_quick(m, 0, qolman_level_get(importance), __func__, formatted, NULL)); \
		free(formatted); \
	} while (0);
#define log_tracef(m, label, ...) logf(m, -2, label, __VA_ARGS__)
#define log_debugf(m, label, ...) logf(m, -1, label, __VA_ARGS__)
#define log_infof(m, label, ...) logf(m, 0, label, __VA_ARGS__)
#define log_warningf(m, label, ...) logf(m, 1, label, __VA_ARGS__)
#define log_errorf(m, label, ...) logf(m, 2, label, __VA_ARGS__)

/*
 * Use qolman manager as qbuild log manager
 */
typedef qolman_manager_t qbuild_logman_t;

/*
 * Creates a log manager
 */
qbuild_result_t qbuild_logman_create(qbuild_logman_t *m);

/*
 * Destroys the given log manager
 */
qbuild_result_t qbuild_logman_destroy(qbuild_logman_t m);

#ifdef __cplusplus
}
#endif

#endif

