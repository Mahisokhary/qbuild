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
		if (!i->initialized) {
			qbuild_runc(c, i->module->destroyer, c, i->data);
			i->initialized = false;
		}
	}
	qstruct_runc(c, qstruct_hashmap_iterator_destroy, it);

	qstruct_runc(c, qstruct_hashmap_destroy, mc->modules);
	log_debugf(c->logman, "Destroyed module system (context=%p)", c);
	return QBUILD_RESULT_OK;
}

