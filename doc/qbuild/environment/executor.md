# Executor
An executor that will execute commands in an environment

## Properties

| name | description              | type                                                 | required |
|------|--------------------------|------------------------------------------------------|----------|
| data | data related to executor | array (unknown type) (size is determined in runtime) | false    |

## Functions

| name       | description                                 | arguments                                      | required |
|------------|---------------------------------------------|------------------------------------------------|----------|
| initilizer | Initilize the executor                      | (`data`)                                       | true     |
| destroyer  | Destroys the executor                       | (`data`)                                       | true     |
| executor   | Executes given command in given environment | (`data`, `environment`, `command`, `process*`) | true     |
> Data is pointer to property `data` of executor

## Implementation
Not implemented

[back](README.md)
