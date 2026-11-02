# Default Platform Detector
Detects an approximate platform at qbuild compile time,
then resolves the exact platform at runtime with help of that.

## POSIX
If the platform is approximately detected as POSIX at compile time,
qbuild determines the exact platform at runtime using `uname(2)`.
The `sysname` field is lowercased and used as the platform name.

## Implementation
- [x] POSIX

[back](README.md)
