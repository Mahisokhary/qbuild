/*
 * QBuild internal helper for qstruct
 */

#ifndef _qbuild_qstruct_internal_h_
#define _qbuild_qstruct_internal_h_

#include <qstruct/qstruct.h>

#ifdef __cplusplus
extern "C" {
#endif

#define qstruct_run(call) do { \
		qstruct_result_t res = call; \
		if (res != QSTRUCT_RESULT_OK) return QBUILD_RESULT_DATASTRUCTURE_FAILED; \
	} while (0);

/*
 * Compares to strings
 */
int8_t _qstruct_comparator_string(const char *x, const char *y);

/*
 * Hasher function
 */
long _qstruct_hasher(const char *x, size_t size, long seed);

#ifdef __cplusplus
}
#endif

#endif

