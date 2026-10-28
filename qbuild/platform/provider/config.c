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

