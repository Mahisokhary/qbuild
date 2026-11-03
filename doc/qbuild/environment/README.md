# doc/qbuild/environment
An environment to execute executables in

## Properties

| name                    | description                                  | type                    | example                              | required |
|-------------------------|----------------------------------------------|-------------------------|--------------------------------------|----------|
| [executor](executor.md) | executes passed commands                     | [executor](executor.md) |                                      | true     |
| directory               | directory the commands should be executed in | `String`                | `/home/user/Projects/project`        | true     |
| variables               | environment variables                        | `Map<String, String>`   | `PATH: /usr/bin, SHELL: /usr/bin/sh` | false    |

## Implementation
Not implemented

[back](../README.md)
