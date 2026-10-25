#include <qbuild/qbuild.internal.h>

qbuild_result_t qbuild_module_init(qbuild_context_t c) {
	struct qbuild_module_context *mc = &c->modules;
	qstruct_runc(c, qstruct_hashmap_create, &mc->modules, &_qstruct_comparator_string, 0, 0, &_qstruct_hasher, 0);
	log_debugf(c->logman, "Initialized module system (context=%p)", c);
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_module_destroy(qbuild_context_t c) {
	struct qbuild_module_context *mc = &c->modules;

	qstruct_hashmap_iterator_t it;
	qstruct_runc(c, qstruct_hashmap_iterator_create, mc->modules, &it);
	while (qstruct_hashmap_iterator_next(it)) {
		struct qbuild_module_instance *i;
		qstruct_runc(c, qstruct_hashmap_iterator_current_value_getp, it, (void **) &i);
		qbuild_module_t m = i->module;
		log_debugf(c->logman, "Destroing module %s (context=%p)", i->module->name, c);
		if (i->initialized) {
			qbuild_runc(c, i->module->destroyer, c, i->data);
			i->initialized = false;
		}
	}
	qstruct_runc(c, qstruct_hashmap_iterator_destroy, it);

	qstruct_runc(c, qstruct_hashmap_destroy, mc->modules);
	log_debugf(c->logman, "Destroyed module system (context=%p)", c);
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_module_load(qbuild_context_t c, qbuild_module_t m) {
	log_debugf(c->logman, "Loading module %s (context=%p)", m->name, c);
	size_t name_size = strlen(m->name) + 1;
	struct qbuild_module_context *mc = &c->modules;
	struct qbuild_module_instance *i;
	if (!qstruct_hashmap_has(mc->modules, m->name, name_size)) {
		qstruct_runc(c, qstruct_hashmap_add, mc->modules, m->name, name_size, NULL, sizeof(struct qbuild_module_instance) + m->data_size);
		qstruct_runc(c, qstruct_hashmap_getp, mc->modules, m->name, name_size, (void **) &i, NULL);
		i->module = m;
	} else {
		qstruct_runc(c, qstruct_hashmap_getp, mc->modules, m->name, name_size, (void **) &i, NULL);
		if (i->module != m) return QBUILD_RESULT_MODULE_NONUNIQUE_NAME;
		if (i->initialized) return QBUILD_RESULT_OK;
	}

	for (int i = 0; i < m->dependencies_length; i++) {
		qbuild_module_t dependency = m->dependencies[0];
		log_tracef(c->logman, "Loading dependency %s of module %s (if not loaded already)", dependency->name, m->name);
		qbuild_runc(c, qbuild_module_load, c, dependency);
	}

	qbuild_runc(c, m->initializer, c, i->data);
	i->initialized = true;
	log_debugf(c->logman, "Loaded module %s (context=%p)", m->name, c);
	return QBUILD_RESULT_OK;
}

qbuild_result_t qbuild_module_data(qbuild_context_t c, qbuild_module_t m, void **datap) {
	size_t name_size = strlen(m->name) + 1;
	struct qbuild_module_context *mc = &c->modules;
	if (qstruct_hashmap_has(mc->modules, m->name, name_size)) {
		struct qbuild_module_instance *i;
		qstruct_runc(c, qstruct_hashmap_getp, mc->modules, m->name, name_size, (void **) &i, NULL);
		if (i->module == m) {
			*datap = i->data;
			return QBUILD_RESULT_OK;
		}
	}
	return QBUILD_RESULT_MODULE_NOTFOUND;
}

