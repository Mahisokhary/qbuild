/*
 * QBuild file helper
 * Built to help reading and writing to files
 */

#ifndef _qbuild_file_file_internal_h_
#define _qbuild_file_file_internal_h_

/*
 * Set path separator based on the platform
 */
#if defined(_WIN32) || defined(_WIN64)
#define QBUILD_FILE_PATH_SEPARATOR ';'
#else
#define QBUILD_FILE_PATH_SEPARATOR ':'
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Concatenate given paths
 * For example input is (2, "test", "file.txt") output will be "test/file.txt"
 * NOTE: Caller should free the returned buffer
 */
char *qbuild_file_pathcat(int count, ...);

/*
 * Reads file
 * Creates buffer and writes file content to it
 * Sets size to buffer size
 * NOTE: caller should free buffer after use
 */
qbuild_result_t qbuild_file_read_all(char *file, char **buffer, size_t *size);

/*
 * Separates multiple paths from a string
 * Paths must be separeted with platform path separetor (unix-like: ':', window: ';')
 * To free returned array simply free first element and then the array
 */
char **qbuild_file_path_separate(const char *src, size_t *sizep);

#ifdef __cplusplus
}
#endif

#endif

