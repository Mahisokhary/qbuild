#ifndef _qbuild_command_command_internal_h_
#define _qbuild_command_command_internal_h_

#ifdef __cplusplus
extern "C" {
#endif

struct qbuild_command {
	char *executable;
	size_t arguments_length;
	char *arguments[];
};

#ifdef __cplusplus
}
#endif


#endif

