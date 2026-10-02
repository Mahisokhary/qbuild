#include <qbuild/qbuild.internal.h>

const static char *qbuild_result_strings[] = {
	"OK",
	"JSON_DESERIALIZE_FAILED",
	"JSON_SERIALIZE_FAILED",
	"FILE_NOT_FOUND",
	"CONTEXT_CREATE_FAILED",
	"DATASTRUCTURE_FAILED",
	"LOGGING_FAILED",
	"PLATFORM_DETECTION_FAILED",
};

const char *qbuild_result_string(qbuild_result_t res) {
	if (res > (sizeof(qbuild_result_strings) / sizeof(qbuild_result_strings[0])))
		return "UNKNOWN";
	return qbuild_result_strings[res];
}

