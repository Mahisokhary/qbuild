#include <qbuild/qbuild.internal.h>
#include <stdarg.h>

char *qbuild_file_pathcat(int count, ...) {
	va_list args;
	va_start(args, count);

	char *first_p = va_arg(args, char *);
	size_t p_size = strlen(first_p) + 1;
	char *p = malloc(p_size);
	strcpy(p, first_p);

	for (int i = 1; i < count; i++) {
		char *new = va_arg(args, char *);
		size_t new_size = strlen(new);
		int index = strlen(p);
		size_t np_size = index + new_size + 2;
		if (np_size > p_size) {
			p_size = np_size;
			p = realloc(p, p_size);
		}
		p[index++] = '/';
		memcpy(&p[index], new, new_size);
		p[p_size - 1] = 0;
	}

	va_end(args);
	return p;
}

/*
 * Calculates size of the file
 */
static inline size_t _qbuild_file_size(FILE *fp) {
	fseek(fp, 0L, SEEK_END);
	size_t res = ftell(fp);
	rewind(fp);
	return res;
}

qbuild_result_t qbuild_file_read_all(char *file, char **buffer, size_t *size) {
	FILE *fp = fopen(file, "r");
	if (!fp) return QBUILD_RESULT_FILE_NOT_FOUND;
	size_t s = _qbuild_file_size(fp);
	char *b = malloc(s);
	s = fread(b, sizeof(char), s, fp);
	fclose(fp);
	*buffer = b;
	*size = s;
	return QBUILD_RESULT_OK;
}

char **qbuild_file_path_separate(const char *src, size_t *sizep) {
	const char s[2] = { QBUILD_FILE_PATH_SEPARATOR, 0 };
	char *dup = strdup(src);
	char *rest = dup;
	char *tok;
	size_t size = 2;
	size_t len = 0;
	char **res = calloc(size, sizeof(char *));
	while ((tok = strtok_r(rest, s, &rest))) {
		if (len + 1 >= size) {
			size *= 2;
			res = realloc(res, size * sizeof(char *));
		}
		res[len++] = tok;
	}
	*sizep = len;
	if (size != len) res = realloc(res, len * sizeof(char *));
	return res;
}

