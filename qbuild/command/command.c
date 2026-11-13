#include <qbuild/qbuild.internal.h>

qbuild_result_t qbuild_command_create(qbuild_command_t *command, const char *executable, char *args[], size_t args_size) {
	qbuild_command_t c; qmalloc(c, sizeof(struct qbuild_command) + (sizeof(char *) * args_size));
	qstrdup(c->executable, executable);
	c->arguments_length = args_size;
	qbuild_string_array_copy(args_size, args, c->arguments);
	*command = c;
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_command_destroy(qbuild_command_t c) {
	free(c->executable);
	for (int i = 0; i < c->arguments_length; i++)
		free(c->arguments[i]);
	free(c);
	return QBUILD_RESULT_OK;
}

const char *qbuild_command_executable(qbuild_command_t c) {
	return c->executable;
}

char **qbuild_command_arguments(qbuild_command_t c, size_t *length) {
	if (length) *length = c->arguments_length;
	return c->arguments;
}

