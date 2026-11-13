#include <qbuild/qbuild.internal.h>

qbuild_result_t qbuild_command_create(qbuild_command_t *command, const char *executable, char *args[], size_t args_size) {
	qbuild_command_t c; qmalloc(c, sizeof(struct qbuild_command) + (sizeof(char *) * args_size));
	qstrdup(c->executable, executable);
	c->arguments_length = args_size;
	qbuild_string_array_copy(args_size, args, c->arguments);
	*command = c;
	return QBUILD_RESULT_OK;
}

