#include <qbuild/qbuild.internal.h>

void qbuild_string_lower(char *buf) {
	for (char *p = buf; *p; p++)
		if ('A' <= *p && *p <= 'Z')
			*p += 'a' - 'A';
}

