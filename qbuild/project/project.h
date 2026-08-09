#ifndef _qbuild_project_project_h_
#define _qbuild_project_project_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pointer to actual project object
 */
typedef struct qbuild_project* qbuild_project_t;

/*
 * Loads project at given directory
 */
qbuild_result_t qbuild_project_load(qbuild_project_t *project, char *dir);

/*
 * Destroys the project object and free used memory
 */
qbuild_result_t qbuild_project_destroy(qbuild_project_t project);

/*
 * Returns pointer to name of the project
 */
char* qbuild_project_name(qbuild_project_t project);

/*
 * Returns pointer to version of the project
 */
char* qbuild_project_version(qbuild_project_t project);

#ifdef __cplusplus
}
#endif

#endif

