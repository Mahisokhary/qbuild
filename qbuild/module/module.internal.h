#ifndef _qbuild_module_module_internal_h_
#define _qbuild_module_module_internal_h_


#ifdef __cplusplus
extern "C" {
#endif

/*
 * A module
 */
struct qbuild_module {
	const char *name;
	qbuild_result_t (*initializer)(qbuild_context_t context, void *data);
	qbuild_result_t (*destroyer)(qbuild_context_t context, void *data);
	size_t data_size;
	size_t dependencies_length;
	const struct qbuild_module **dependencies;
};

/*
 * An instance of a module
 */
struct qbuild_module_instance {
	const struct qbuild_module *module;
	bool initialized;
	char data[];
};

/*
 * Context for module system
 */
struct qbuild_module_context {
	/*
	 * Contains modules in the context with module name as key and module instance as value
	 */
	qstruct_hashmap_t modules;
};

#ifdef __cplusplus
}
#endif

#endif

