# Introduction

The Ox-Extends Library, based on Ox codebase.
Supports terminal, gui, string, etc.
It can be used in both [C++](https://cplusplus.com) and [D](https://dlang.org)

# Warning

Old [ox](https://github.com/ACoderOrHacker/ox) is actually deprecated.
DO NOT USE IT.

# File Structure

| Directory/File                                  | Description                                                     |
| ----------------------------------------------- | --------------------------------------------------------------- |
| `LICENSE`                                       | License file                                                    |
| `README.md`                                     | Short introduction                                              |
| `CONTRIBUTING.md`                               | Contributing guidelines                                         |
| `.editorconfig`, `.clang-tidy`, `.clang-format` | Code style configuration files                                  |
| `dub.sdl`                                       | [DUB](https://dub.pm) project file                              |
| `xmake.lua`                                     | [xmake](https://xmake.io) build file, use this to build C++ & D |
| `remote`                                        | [xmake](https://xmake.io) remote package files                  |
| `scripts`                                       | Useful scripts for publishing, packing, etc.                    |
| `modules`                                       | [C++](https://cplusplus.com) 20 modules                         |
| `src`                                           | [C++](https://cplusplus.com) source code                        |
| `include`                                       | [C++](https://cplusplus.com) header files                       |
| `source`                                        | [D](https://dlang.org) source code                              |
| `examples`                                      | Example programs                                                |
| `tests`                                         | Test programs                                                   |
| `metas`                                         | Gives metainfos and configs for the project                     |

# Dependencies

## Building Dependencies

[Xmake](https://xmake.io) is for building.

[DUB](https://dub.pm) is used for publishing in dub (building is also ok).
You can also use [scripts/install_dub_deps.d](scripts/install_dub_deps.d) to install dependencies for DUB and then build.
Every dependency will be installed into `dub_dependencies` before committing.

## Packing Dependencies

[FPack](https://github.com/ACoderOrHacker/fpack) is for packing.
Run

```sh
fpack install
```

to install the required tools for packing.

# Building

Run `xmake` to build the project.
You can also use these following options in building:

- `--shared=true/false` - Build shared libraries (default is `false`).
- `--modules=true/false` - Build With C++20 modules (default is `false`).

# Packaging

Run `xmake pack-oe` to package the project.

# Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for more information.

# License

This library is under the Apache License 2.0.
