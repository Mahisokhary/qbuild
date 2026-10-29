# doc/qbuild/command
Simply a command like `make build`

## Properties
| name          | description                     | type       | example                        | required |
|---------------|---------------------------------|------------|--------------------------------|----------|
| executable    | executable to run               | `string`   | `make`, `/bin/make`            | true     |
| arguements    | arguments to pass to executable | `string[]` | `null`, `{ "clean", "build" }` | false    |

## Implementation
Not implemented

[back](../README.md)
