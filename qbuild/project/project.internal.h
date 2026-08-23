#ifndef _qbuild_project_project_internal_h_
#define _qbuild_project_project_internal_h_

#ifdef __cplusplus
extern "C" {
#endif

struct qbuild_project_info {
	char name[30];
	char version[20];
};

struct qbuild_project {
	char *dir;
	struct qbuild_project_info info;
};

#ifdef __cplusplus
}
#endif

#endif

