#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_file_path_seperate() {
	test_run_log("qbuild_file_path_seperate");
	const char sample[] = "test1.txt:test2.txt:test3.txt:test4.txt:test5.txt";
	size_t size;
	char **res;

	bool success = 1;
	success &= (res = qbuild_file_path_separate(sample, &size)) != NULL;
	success &= size == 5;
	for (int i = 0; i < size; i++) {
		success &= memcmp(res[i], &sample[i * 10], 9) == 0;
	}
	free(res[0]);
	free(res);
	test_result_log(success);
	return success;
}

bool test_qbuild_file_exists() {
	test_run_log("qbuild_file_exists");

	bool success = 1;
	success &= qbuild_file_exists("Makefile");
	success &= !qbuild_file_exists("Makefile.dont_exists");
	test_result_log(success);
	return success;
}

bool test_qbuild_file() {
	bool success = true;
	success &= test_qbuild_file_path_seperate();
	success &= test_qbuild_file_exists();
	return success;
}

