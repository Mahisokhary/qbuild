#include <qbuild/qbuild.internal.h>

static qbuild_result_t init(qbuild_context_t c, void *data) {
	struct qbuild_platform_context *pc = data;
	pc->c = c;
	pc->provider = &qbuild_platform_provider_config;
	pc->detector = &qbuild_platform_detector_default;
	qstruct_runc(c, qstruct_hashmap_create, &pc->loaded, &_qstruct_comparator_string, 0, 0, &_qstruct_hasher, 0);

	char *host_name;
	qbuild_runc(c, pc->detector, c, &host_name);
	if (!host_name) {
		log_errorf(c->logman, "Failed to detect host platform (context=%p)", c);
		return QBUILD_RESULT_PLATFORM_DETECTION_FAILED;
	}
	log_debugf(c->logman, "Detected host platform: %s (context=%p)", host_name, c);
	qbuild_runc(c, qbuild_platform_fetch, pc, host_name, &pc->host);
	free(host_name);

	pc->target = pc->host;
	return QBUILD_RESULT_OK;
}

static qbuild_result_t destroy_loaded(qbuild_context_t c, struct qbuild_platform_context *pc) {
	qstruct_hashmap_iterator_t it;
	qstruct_runc(c, qstruct_hashmap_iterator_create, pc->loaded, &it);
	while (qstruct_hashmap_iterator_next(it)) {
		qbuild_platform_t p;
		qstruct_runc(c, qstruct_hashmap_iterator_current_value_getp, it, (void **) &p);
		free(p->name);
		if (p->parents_length != 0) free(p->parents);
	}
	qstruct_runc(c, qstruct_hashmap_iterator_destroy, it);
	qstruct_runc(c, qstruct_hashmap_destroy, pc->loaded);
	return QBUILD_RESULT_OK;
}

inline static qbuild_result_t destroy(qbuild_context_t c, void *data) {
	struct qbuild_platform_context *pc = data;
	qbuild_runc(c, destroy_loaded, c, pc);
	return QBUILD_RESULT_OK;
}

static const struct qbuild_module module = {
	QBUILD_PLATFORM_MODULE_NAME,
	&init, &destroy,
	sizeof(struct qbuild_platform_context),
	0, NULL
};

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

qbuild_result_t qbuild_platform_load(qbuild_platform_context_t pc, const char *name) {
	qbuild_context_t c = pc->c;
	qbuild_runc(c, pc->provider, c, pc, name);
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_platform_fetch(qbuild_platform_context_t pc, const char *name, qbuild_platform_t *p) {
	qbuild_context_t c = pc->c;
	qbuild_runc(c, qbuild_platform_load, pc, name);
	qstruct_runc(c, qstruct_hashmap_getp, pc->loaded, name, strlen(name) + 1, (void **) p, NULL);
	return QBUILD_RESULT_OK;
}

