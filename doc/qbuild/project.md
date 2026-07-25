# Project
A project built by qbuild

## Properties
- project dir: Where project is stored
- [project info](#project-info): information about a project

### Project info
Information about the project

| >info   | rules                                                | example          |
|---------|------------------------------------------------------|------------------|
| name    | lower-case and `-` sepperted                         | `qbuild-example` |
| version | dot sepperatted numbers, may have suffix like `beta` | `1.0.0-beta`     |
> These info should be stored at file `project.jsonc` at project dir.

## Implementation
- [qbuild/project/project.h](../../qbuild/project/project.h):
- - Defined `qbuild_project_t` as pointer to project object
- - Defined `qbuild_project_load` function to load project info at given directory
- [qbuild/project/project.internal.h](../../qbuild/project/project.internal.h):
- - Defined struct `qbuild_project` to hold project
- - Defined struct `qbuild_project_info` to hold project information

[back](index.md)
