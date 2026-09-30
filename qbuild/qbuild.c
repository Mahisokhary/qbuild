#include <qbuild/qbuild.internal.h>

const static char *qbuild_result_strings[] = {
	"QBUILD_RESULT_OK",
	"QBUILD_RESULT_JSON_DESERIALIZE_FAILED",
	"QBUILD_RESULT_JSON_SERIALIZE_FAILED",
	"QBUILD_RESULT_FILE_NOT_FOUND",
	"QBUILD_RESULT_CONTEXT_CREATE_FAILED",
	"QBUILD_RESULT_DATASTRUCTURE_FAILED",
	"QBUILD_RESULT_LOGGING_FAILED",
	"QBUILD_RESULT_PLATFORM_DETECTION_FAILED",
};

const char *qbuild_result_string(qbuild_result_t res) {
	if (res > (sizeof(qbuild_result_strings) / sizeof(qbuild_result_strings[0])))
		return "UNKNOWN";
	return qbuild_result_strings[res];
}

