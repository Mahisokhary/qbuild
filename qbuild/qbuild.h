#ifndef _qbuild_qbuild_h_
#define _qbuild_qbuild_h_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	QBUILD_RESULT_OK = 0, // Operation successful
	QBUILD_RESULT_JSON_DESERIALIZE_FAILED = 1, // Failed to deserialize json
	QBUILD_RESULT_JSON_SERIALIZE_FAILED = 2, // Failed to serialize json
	QBUILD_RESULT_FILE_NOT_FOUND = 3, // Requested file not found
	QBUILD_RESULT_CONTEXT_CREATE_FAILED = 4, // Failed to load resources needed for creating context
	QBUILD_RESULT_DATASTRUCTURE_FAILED = 5, // Datastructure operation failed
} qbuild_result_t;

#ifdef __cplusplus
}
#endif

#include <qbuild/project/project.h>
#include <qbuild/context/context.h>
#include <qbuild/platform/platform.h>

#endif

