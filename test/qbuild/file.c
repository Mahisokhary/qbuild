#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_file_path_seperate() {
	test_run_log();
	const char sample[] = "test1.txt:test2.txt:test3.txt:test4.txt:test5.txt";
	size_t size;
	char **res;

	bool success = 1;
	test(success, exit, (res = qbuild_file_path_separate(sample, &size)) != NULL);
	test(success, free, size == 5);
	for (int i = 0; i < size; i++) {
		test(success, free, memcmp(res[i], &sample[i * 10], 9) == 0);
	}
free:
	free(res[0]);
	free(res);
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_file_exists() {
	test_run_log();

	bool success = 1;
	test(success, exit, qbuild_file_exists("Makefile"));
	test(success, exit, !qbuild_file_exists("Makefile.dont_exists"));
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_file_find() {
	test_run_log();
	const char *paths[] = {
		".",
		"./example",
	};
	size_t paths_length = 2;

	bool success = 1;

	char *file = qbuild_file_find(paths, paths_length, "Makefile");
	test(success, destroy, file && !strcmp(file, "./Makefile"));

	char *file2 = qbuild_file_find(paths, paths_length, "project.jsonc");
	test(success, destroy, file2 && !strcmp(file2, "./example/project.jsonc"));

	char *file3 = qbuild_file_find(paths, paths_length, "Makefile.dont_exists");
	test(success, destroy, !file3);
destroy:
	if (file) free(file);
	if (file2) free(file2);
	if (file3) free(file3);
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_file() {
	bool success = true;
	success &= test_qbuild_file_path_seperate();
	success &= test_qbuild_file_exists();
	success &= test_qbuild_file_find();
	return success;
}

