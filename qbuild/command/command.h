#ifndef _qbuild_command_command_h_
#define _qbuild_command_command_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pointer to actual command
 */
typedef struct qbuild_command *qbuild_command_t;

/*
 * Creates a new command with given executable and arguments
 */
qbuild_result_t qbuild_command_create(qbuild_command_t *command, const char *executable, char *args[], size_t args_size);

/*
 * Destroys the command
 */
qbuild_result_t qbuild_command_destroy(qbuild_command_t command);

#ifdef __cplusplus
}
#endif


#endif

