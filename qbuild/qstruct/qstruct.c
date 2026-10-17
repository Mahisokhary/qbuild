#include <qbuild/qbuild.internal.h>
#include <xxhash.h>

int8_t _qstruct_comparator_string(const char *x, const char *y) {
	return strcmp(x, y);
}

long _qstruct_hasher(const char *x, size_t size, long seed) {
	return XXH64(x, size, seed);
}

