#include <qbuild/qbuild.internal.h>

qbuild_result_t qbuild_context_create(qbuild_context_t *ctx) {
	qbuild_context_t c = malloc(sizeof (struct qbuild_context));
	qbuild_run(qbuild_logman_create(&c->logman));

	const char *config_dirs = getenv("QBUILD_CONTEXT_CONFIG_PATH");
	if (!config_dirs) config_dirs = QBUILD_CONTEXT_CONFIG_PATH;
	c->config_dirs = qbuild_file_path_separate(config_dirs, &c->config_dirs_length);
	if (!c->config_dirs) return QBUILD_RESULT_CONTEXT_CREATE_FAILED;

	*ctx = c;
	log_debugf(c->logman, "Initialized context %p", c);
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_context_destroy(qbuild_context_t c) {
	free(c->config_dirs[0]);
	free(c->config_dirs);
	free(c);
	log_debugf(c->logman, "Destroyed context %p", c);
	qbuild_run(qbuild_logman_destroy(c->logman));
	return QBUILD_RESULT_OK;
}

char** qbuild_context_config_dirs(qbuild_context_t c, size_t *length) {
	*length = c->config_dirs_length;
	return c->config_dirs;
}

