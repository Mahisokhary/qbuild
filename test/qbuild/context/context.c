#include <test/test.h>
#include <qbuild/qbuild.internal.h>

bool test_qbuild_context_create_destroy() {
	test_run_log();
	qbuild_context_t ctx;

	bool success = 1;
	test_run(success, exit, qbuild_context_create(&ctx));

	size_t len;
	char **dirs = qbuild_context_config_dirs(ctx, &len);
	test(success, destroy, len == 1);
	test(success, destroy, strcmp(dirs[0], "./qbuild/config/") == 0);
destroy:
	test_run(success, exit, qbuild_context_destroy(ctx));
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_context_config_fetch() {
	test_run_log();
	qbuild_context_t ctx;
	char *config;

	bool success = 1;
	test_run(success, exit, qbuild_context_create(&ctx));
	config = qbuild_context_config_fetch(ctx, "platform/linux.jsonc");
	test(success, destroy_config, config);
	test(success, destroy_ctx, qbuild_file_exists(config));
destroy_config:
	free(config);
destroy_ctx:
	test_run(success, exit, qbuild_context_destroy(ctx));
exit:
	test_result_log(success);
	return success;
}

bool test_qbuild_context() {
	bool success = true;
	success &= test_qbuild_context_create_destroy();
	success &= test_qbuild_context_config_fetch();
	return success;
}

