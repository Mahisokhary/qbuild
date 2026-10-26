#include <qbuild/qbuild.internal.h>

bool qbuild_platform_has(qbuild_platform_context_t pc, const char *name) {
	return qstruct_hashmap_has(pc->loaded, name, strlen(name) + 1);
}

qbuild_result_t qbuild_platform_register(qbuild_platform_context_t pc, const char *name, size_t parents_length, const qbuild_platform_t *parents) {
	qbuild_context_t c = pc->c;
	if (!qbuild_platform_has(pc, name)) {
		qbuild_platform_t *copied_parents;
		if (parents_length) {
			copied_parents = malloc(sizeof(qbuild_platform_t) * parents_length);
			memcpy(copied_parents, parents, sizeof(qbuild_platform_t) * parents_length);
		} else {
			copied_parents = NULL;
		}
		struct qbuild_platform p = { strdup(name), parents_length, copied_parents };
		qstruct_runc(c, qstruct_hashmap_add, pc->loaded, name, strlen(name) + 1, &p, sizeof(struct qbuild_platform));
		log_debugf(c->logman, "Registered platform: %s (context=%p)", name, c);
	}
	return QBUILD_RESULT_OK;
}

