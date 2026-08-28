#ifndef _qbuild_platform_platform_internal_h_
#define _qbuild_platform_platform_internal_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Platform
 */
struct qbuild_platform {
	char *name;
	size_t parents_length;
	struct qbuild_platform **parents;
};

/*
 * Platform context
 */
struct qbuild_platform_context {
	qstruct_hashmap_t loaded;	// All loaded platforms
	qbuild_platform_t host;		// Host platform
	qbuild_platform_t target;	// Target platform
};

#ifdef __cplusplus
}
#endif

#endif

