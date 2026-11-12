/*
 * QBuild string helper
 * Built to help operations on strings
 */

#ifndef _qbuild_string_string_internal_h_
#define _qbuild_string_string_internal_h_

#ifdef __cplusplus
extern "C" {
#endif

#define qstrdup(var, str) do { \
	var = strdup(str); \
	if (!var) return QBUILD_RESULT_OUT_OF_MEMORY; \
	} while(0);

/*
 * Converts all upper-cased chars to lower-case
 */
void qbuild_string_lower(char *buf);

/*
 * Format given format string with given paramether and returns a buffer
 * WARGNING: buffer should be freed by caller!
 */
char *qbuild_string_format(const char *fmt, ...);

/*
 * Duplicates given array of strings
 * WARNING: Caller must free array and all of its elements
 */
char **qbuild_string_array_dup(size_t arr_size, char **arr);

/*
 * Copies strings in first array to second array
 * WARNING: Strings added to second array are duplicated and caller must free them
 */
void qbuild_string_array_copy(size_t arr_size, char **arr, char **narr);

#ifdef __cplusplus
}
#endif

#endif

