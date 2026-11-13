#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_command_create_destroy() {
	test_run_log();
	qbuild_command_t cmd;
	char **arguments;
	size_t arguments_length;

	bool success = true;
	test_run(success, exit, qbuild_command_create(&cmd, "ls", NULL, 0));
	test(success, destroy, strcmp(qbuild_command_executable(cmd), "ls") == 0);
	arguments = qbuild_command_arguments(cmd, &arguments_length);
	test(success, destroy, arguments_length == 0);
destroy:
	test_run(success, exit, qbuild_command_destroy(cmd));
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_command() {
	bool success = true;
	success &= test_qbuild_command_create_destroy();
	return success;
}

