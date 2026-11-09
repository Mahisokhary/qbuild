#include <qbuild/qbuild.internal.h>
#include <stdarg.h>

void qbuild_string_lower(char *buf) {
	for (char *p = buf; *p; p++)
		if ('A' <= *p && *p <= 'Z')
			*p += 'a' - 'A';
}

char *qbuild_string_format(const char *fmt, ...) {
	va_list ap, ap2;
	va_start(ap, fmt);
	va_copy(ap2, ap);

	size_t len = vsnprintf(NULL, 0, fmt, ap) + 1;
	va_end(ap);

	char *buffer = malloc(len);
	if (!buffer) return NULL;

	int r = vsnprintf(buffer, len, fmt, ap2);
	va_end(ap);
	return buffer;
}

char **qbuild_string_array_dup(size_t arr_size, char **arr) {
	char **narr = malloc(sizeof(char *) * arr_size);
	qbuild_string_array_copy(arr_size, arr, narr);
	return narr;
}

void qbuild_string_array_copy(size_t arr_size, char **arr, char **narr) {
	for (int i = 0; i < arr_size; i++) {
		narr[i] = strdup(arr[i]);
	}
}

