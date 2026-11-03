# doc/qbuild/process
A process launched and managed by `qbuild`.

## Properties

| Name   | Description                                                             | Type    |
|--------|-------------------------------------------------------------------------|---------|
| pid    | ProcessID of the process                                                | `int`   |
| stdout | Standard output of the process, provided as a file pointer (read mode)  | `FILE*` |
| stdin  | Standard input of the process, provided as a file pointer (append mode) | `FILE*` |
| stderr | Standard error of the process, provided as a file pointer (read mode)   | `FILE*` |

## Functions
| Name      | Description                                                    | Arguments                             | Return type |
|-----------|----------------------------------------------------------------|---------------------------------------|-------------|
| is alive  | Checks if the process is alive                                 | `process`                             | `bool`      |
| exit code | Fetches exit code of the process (fails if process not exited) | `process`, `int *exitcode`            | -           |
| wait      | Waits for the process to exits                                 | `process`, `int *exitcode (nullsafe)` | -           |
> Return type `-` means `qbuild_result_t` is returned

## Implementation
Not implemented

[back](../README.md)
