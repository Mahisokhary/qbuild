#include <qbuild/qbuild.internal.h>

/*
 * Returns arraylist of platforms that the platform extends
 * qson deserialize context: subctx for "extends" array
 */
inline static qbuild_result_t deserialize_extends_array(qbuild_context_t qc, qbuild_platform_context_t pc, qson_deserialize_ctx_t c, qstruct_arraylist_t *list) {
	qson_deserialize_run(qson_deserialize_array_start(c));
	bool has_next = qson_deserialize_ctx_state(c) == QSON_DESERIALIZING_STATE_ARRAY;
	qson_type_t type = QSON_TYPE_STRING;

	qstruct_arraylist_t l;
	qstruct_arraylist_create(&l, sizeof(qbuild_platform_t), 0);

	char *name;
	size_t name_size;
	if (qson_deserialize_ctx_state(c) == QSON_DESERIALIZING_STATE_ARRAY) {
		while (has_next) {
			qson_deserialize_run(qson_deserialize_array_entry(c, &type));
			qson_deserialize_run(qson_deserialize_array_entry_value_string_auto(c, &name, &name_size, &has_next));
			qbuild_platform_t p;
			qbuild_runc(qc, qbuild_platform_fetch, pc, name, &p);
			qstruct_arraylist_add(l, &p);
			free(name);
		}
	}

	*list = l;
	return QBUILD_RESULT_OK;
}

/*
 * Handles "extends" field of platform
 */
inline static qbuild_result_t derialize_extends(qbuild_context_t c, qbuild_platform_context_t pc, qson_deserialize_ctx_t ctx, qbuild_platform_t p, bool *has_next) {
	qson_deserialize_ctx_t sc;
	qstruct_arraylist_t l;

	qson_deserialize_run(qson_deserialize_object_entry_value_sub_ctx(ctx, &sc));
	qbuild_runc(c, deserialize_extends_array, c, pc, sc, &l);
	qson_deserialize_run(qson_deserialize_object_entry_value_sub_ctx_end(ctx, sc, has_next));

	if (qstruct_arraylist_length(l) != 0) {
		p->parents = qstruct_arraylist_convert_array(l, &p->parents_length);
	} else {
		qstruct_arraylist_destroy(l);
	}
	return QBUILD_RESULT_OK;
}

/*
 * Finds config file file for the given platform name
 */
inline static char *find_config_file(qbuild_context_t c, const char *name) {
	char *pfile_name = qbuild_string_format("platform/%s.jsonc", name);
	char *pfile = qbuild_context_config_fetch(c, pfile_name);
	free(pfile_name);
	return pfile;
}

inline static qbuild_result_t load(qbuild_context_t c, qbuild_platform_context_t pc, const char *name, size_t name_size, qbuild_platform_t sp) {
	sp->name = strdup(name);
	sp->parents = NULL;
	sp->parents_length = 0;

	size_t buffer_size;
	char *buffer;
	char *pfile = find_config_file(c, name);
	if (pfile == NULL) return QBUILD_RESULT_FILE_NOT_FOUND;
	qbuild_runc(c, qbuild_file_read_all, pfile, &buffer, &buffer_size);
	free(pfile);

	qson_deserialize_ctx_t ctx;
	qson_deserialize_run(qson_deserialize_ctx_create(&ctx, buffer, buffer_size - 1));
	qson_deserialize_run(qson_deserialize_object_start(ctx));
	if (qson_deserialize_ctx_state(ctx) != QSON_DESERIALIZING_STATE_OBJECT) return QBUILD_RESULT_JSON_DESERIALIZE_FAILED;
	char *key;
	size_t key_size;
	bool has_next = true;
	while (has_next) {
		qson_type_t type = QSON_TYPE_AUTO;
		qson_deserialize_run(qson_deserialize_object_entry_auto(ctx, &key, &key_size, &type));
		if (strcmp(key, "extends") == 0 && !sp->parents) {
			if (type != QSON_TYPE_ARRAY) return QBUILD_RESULT_JSON_DESERIALIZE_FAILED;
			qbuild_runc(c, derialize_extends, c, pc, ctx, sp, &has_next);
		} else {
			qson_deserialize_run(qson_deserialize_object_entry_value_skip(ctx, &has_next));
		}
		free(key);
	}
	qson_deserialize_run(qson_deserialize_ctx_destroy(ctx));
	free(buffer);
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_platform_provider_config(qbuild_context_t c, qbuild_platform_context_t pc, const char *name) {
	size_t name_size = strlen(name) + 1;
	if (!qstruct_hashmap_has(pc->loaded, name, name_size)) {
		size_t parents_length;
		qbuild_platform_t *parents;
		struct qbuild_platform sp;
		qbuild_runc(c, load, c, pc, name, name_size, &sp);
		qbuild_runc(c, qbuild_platform_register, pc, name, sp.parents_length, sp.parents);
		free(sp.name);
		free(sp.parents);
	}
	return QBUILD_RESULT_OK;
}

