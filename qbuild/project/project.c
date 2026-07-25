#include "project.internal.h"

/*
 * Loads project info from project info file at project directory
 */
inline static qbuild_result_t _load_project_info(struct qbuild_project *p) {
	char *path = qbuild_file_pathcat(2, p->dir, "project.jsonc");
	size_t buffer_size;
	char *buffer;
	qbuild_run(qbuild_file_read_all(path, &buffer, &buffer_size));
	free(path);

	qson_deserialize_ctx_t ctx;
	struct qbuild_project_info *i = &p->info;
	qson_deserialize_run(qson_deserialize_ctx_create(&ctx, buffer, buffer_size));
	qson_deserialize_run(qson_deserialize_object_start(ctx));
	if (qson_deserialize_ctx_state(ctx) != QSON_DESERIALIZING_STATE_OBJECT) return QBUILD_RESULT_JSON_DESERIALIZE_FAILED;
	char key[30];
	bool has_next = true;
	while (has_next) {
		qson_type_t type = QSON_TYPE_AUTO;
		int key_size = sizeof(key);
		qson_deserialize_run(qson_deserialize_object_entry(ctx, key, &key_size, &type));
		if (strcmp(key, "name") == 0) {
			if (type != QSON_TYPE_STRING) return QBUILD_RESULT_JSON_DESERIALIZE_FAILED;
			int size = sizeof(i->name);
			qson_deserialize_run(qson_deserialize_object_entry_value_string(ctx, i->name, &size, &has_next));
		} else if (strcmp(key, "version") == 0) {
			if (type != QSON_TYPE_STRING) return QBUILD_RESULT_JSON_DESERIALIZE_FAILED;
			int size = sizeof(i->version);
			qson_deserialize_run(qson_deserialize_object_entry_value_string(ctx, i->version, &size, &has_next));
		} else {
			return QBUILD_RESULT_JSON_DESERIALIZE_FAILED;
		}
	}
	qson_deserialize_run(qson_deserialize_ctx_destroy(ctx));
	free(buffer);
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_project_load(qbuild_project_t *project, char *dir) {
	struct qbuild_project *p = malloc(sizeof(struct qbuild_project));

	char *ndir = malloc(strlen(dir) + 1);
	strcpy(ndir, dir);
	p->dir = ndir;

	qbuild_run(_load_project_info(p));
	*project = p;
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_project_destroy(qbuild_project_t project) {
	struct qbuild_project *p = project;
	free(p->dir);
	free(p);
	return QBUILD_RESULT_OK;
}

char* qbuild_project_name(qbuild_project_t project) {
	struct qbuild_project *p = project;
	return (&p->info)->name;
}

char* qbuild_project_version(qbuild_project_t project) {
	struct qbuild_project *p = project;
	return (&p->info)->version;
}

