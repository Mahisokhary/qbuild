#include "context.internal.h"

qbuild_result_t qbuild_context_create(qbuild_context_t *ctx) {
	qbuild_context_t c = malloc(sizeof (struct qbuild_context));

	const char *config_dirs = getenv("QBUILD_CONTEXT_CONFIG_PATH");
	if (!config_dirs) config_dirs = QBUILD_CONTEXT_CONFIG_PATH;
	c->config_dirs = qbuild_file_path_separate(config_dirs, &c->config_dirs_length);
	if (!c->config_dirs) return QBUILD_RESULT_CONTEXT_CREATE_FAILED;

	*ctx = c;
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_context_destroy(qbuild_context_t c) {
	free(c->config_dirs[0]);
	free(c->config_dirs);
	free(c);
	return QBUILD_RESULT_OK;
}

