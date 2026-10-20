#include <qbuild/qbuild.internal.h>

qbuild_result_t qbuild_module_init(qbuild_context_t c) {
	struct qbuild_module_context *mc = &c->modules;
	qstruct_runc(c, qstruct_hashmap_create, &mc->modules, &_qstruct_comparator_string, 0, 0, &_qstruct_hasher, 0);
	log_debugf(c->logman, "Initialized module system (context=%p)", c);
	return QBUILD_RESULT_OK;
}

