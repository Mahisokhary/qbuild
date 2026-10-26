#include <qbuild/qbuild.internal.h>

bool qbuild_platform_has(qbuild_platform_context_t pc, const char *name) {
	return qstruct_hashmap_has(pc->loaded, name, strlen(name) + 1);
}

