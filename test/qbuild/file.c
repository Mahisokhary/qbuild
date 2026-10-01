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

bool test_qbuild_file() {
	bool success = true;
	success &= test_qbuild_file_path_seperate();
	success &= test_qbuild_file_exists();
	return success;
}

