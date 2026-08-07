# Platform
A platform is something able to run programs. \
It can be an OS like `windows`, a kernel like `linux` or a standard like `posix`. \
A platform contains its own specific libraries and syscalls which can be used by platform specific codes. \
Platform `generic` is a special platform, code written for it is used for all target platform

## Architecture
And can be on specific arch like `x86_64` or `aarch64`

## Inheritance
A platform can extend another platform for example `linux` and `freebsd` extend `posix`

## Configuration
platforms can contain custom configs for compatibility or optimization

## Host and Target
Host platform is platform which qbuild is running on. \
Target platform is platform which qbuild is building project for.
> Cross-compiling is possible with qbuild

> Generic cannot be used as target

## Support
Platforms supported by qbuild

| Platform name | host | target |
|:-------------:|:----:|:------:|
|    generic    | yes  |   -    |

## Implementation
Not implemented

[back](index.md)
