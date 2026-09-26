<div align="center">

<img src="docs/assets/cforge-social-preview.jpg" alt="cForge — C Standard Library Reimplementation" width="100%">

# cForge

**A C Standard Library Reimplementation**

[![C](https://img.shields.io/badge/C-C17-00599C?logo=c&logoColor=white)](https://en.cppreference.com/w/c/17)
[![CMake](https://img.shields.io/badge/CMake-Build-064F8C?logo=cmake&logoColor=white)](https://cmake.org/)
[![GCC](https://img.shields.io/badge/GCC-Supported-5C6BC0?logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Clang](https://img.shields.io/badge/Clang-Supported-262D3A?logo=llvm&logoColor=white)](https://clang.llvm.org/)
[![CI](https://github.com/Ahren27/cforge/actions/workflows/ci.yml/badge.svg)](https://github.com/Ahren27/cforge/actions/workflows/ci.yml)
[![License](https://img.shields.io/github/license/Ahren27/cforge)](LICENSE)
[![Code Style](https://img.shields.io/badge/code%20style-clang--format-blue)](https://clang.llvm.org/docs/ClangFormat.html)

*A from-scratch implementation of C standard library functionality, built to explore systems programming, memory management, library interfaces, testing, debugging, and portable C.*

</div>

---

## About

**cForge** is a from-scratch reimplementation of functionality from the C Standard Library.

The project is designed as a hands-on systems programming exercise for developing a deeper understanding of how common C library functions behave beneath their familiar APIs.

Rather than simply reproducing function signatures, cForge focuses on:

- Correct behavior and edge-case handling
- Pointer and memory manipulation
- Undefined-behavior awareness
- Defensive testing
- Portable C
- Debugging with sanitizers and Valgrind
- Maintainable project structure
- Continuous integration
- Professional Git and pull-request workflows

> [!IMPORTANT]
> cForge is an educational project and is **not intended to replace a production system C library** such as glibc, musl, or the platform-provided libc.

---

## Goals

The primary goals of cForge are to:

- Build a deeper understanding of the C programming language
- Explore how common C Standard Library functions work internally
- Practice low-level memory and pointer manipulation
- Write well-tested systems code
- Learn to identify and avoid undefined behavior
- Practice debugging memory-related defects
- Develop portable code using GCC and Clang
- Apply professional software-engineering practices to a C project

Where practical, implementations are tested against behavior defined by the relevant C standard.

---

## Project Status

> 🚧 **cForge is currently under active development.**

Functions and headers are being implemented incrementally.

The project is intended to cover functionality associated with areas such as:

| Header | Area |
| --- | --- |
| `<string.h>` | Strings and memory manipulation |
| `<ctype.h>` | Character classification and conversion |
| `<stdlib.h>` | Conversion, allocation, algorithms, and utilities |
| `<stdio.h>` | Input and output |
| `<stdint.h>` | Fixed-width integer types and related utilities |

See [`docs/supported-functions.md`](docs/supported-functions.md) for current implementation status.

---

## Repository Structure

```text id="cuxbqf"
cforge/
├── .github/
│   ├── ISSUE_TEMPLATE/
│   ├── workflows/
│   │   └── ci.yml
│   └── pull_request_template.md
│
├── cmake/
│   ├── CompilerWarnings.cmake
│   └── Sanitizers.cmake
│
├── docs/
│   ├── assets/
│   │   └── cforge-social-preview.jpg
│   ├── design.md
│   └── supported-functions.md
│
├── include/
│   └── cforge/
│
├── src/
│
├── tests/
│   └── CMakeLists.txt
│
├── .clang-format
├── .clang-tidy
├── .editorconfig
├── .gitignore
├── CMakeLists.txt
├── CMakePresets.json
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── LICENSE
├── README.md
└── SECURITY.md
```

Public interfaces live under `include/cforge/`, implementations live under `src/`, and automated tests are kept separately under `tests/`.

---

## Building

### Requirements

cForge is designed to build with a modern C toolchain.

Recommended tools:

- C17-compatible compiler
  - GCC
  - Clang
- CMake
- CTest
- Criterion
- Valgrind
- AddressSanitizer
- UndefinedBehaviorSanitizer

### Clone

```bash id="ws4qhn"
git clone https://github.com/Ahren27/cforge.git
cd cforge
```

### Configure

```bash id="ik70y9"
cmake -S . -B build
```

### Build

```bash id="rdtr4m"
cmake --build build
```

For parallel builds:

```bash id="skafqc"
cmake --build build -j
```

---

## CMake Presets

cForge uses CMake as its primary build system.

When presets are configured, common development workflows can be simplified with commands such as:

```bash id="9ly8ny"
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

Additional presets can be added for configurations such as:

```text id="rjq37i"
debug
release
asan
ubsan
```

This keeps compiler settings, sanitizer configurations, and build options centralized in CMake rather than maintaining separate build systems.

---

## Testing

Tests are written to exercise:

- Normal inputs
- Empty inputs
- Boundary conditions
- Return values
- Pointer behavior
- Memory behavior
- Regression cases
- Defined edge cases from the C standard

Run the test suite with:

```bash id="q0eqz3"
ctest --test-dir build --output-on-failure
```

When appropriate, results may also be compared against the host system's C library for inputs whose behavior is defined by the standard.

> [!NOTE]
> Some C library functions specify properties of a result rather than an exact value. For example, comparison functions may specify whether the result is negative, zero, or positive without specifying the exact numeric value.

---

## Memory Safety

Because many C Standard Library functions operate directly on memory, memory correctness is a major focus of cForge.

### AddressSanitizer

```bash id="057vv3"
cmake -S . -B build-asan \
    -DCMAKE_C_FLAGS="-fsanitize=address -fno-omit-frame-pointer"

cmake --build build-asan

ctest --test-dir build-asan --output-on-failure
```

### UndefinedBehaviorSanitizer

```bash id="s43rbo"
cmake -S . -B build-ubsan \
    -DCMAKE_C_FLAGS="-fsanitize=undefined"

cmake --build build-ubsan

ctest --test-dir build-ubsan --output-on-failure
```

### Valgrind

```bash id="xw0ep7"
valgrind \
    --leak-check=full \
    --show-leak-kinds=all \
    ./build/tests/<test-executable>
```

Valgrind should generally be run separately from sanitizer-instrumented builds.

---

## Compiler Support

cForge aims to remain portable across major C compilers.

CI should validate the project using at least:

| Compiler | Status |
| --- | --- |
| GCC | Supported |
| Clang | Supported |

Compiler-specific extensions should be avoided unless there is a clear reason to use them.

The project should compile with strict warnings enabled whenever practical.

Example:

```text id="al2wsg"
-Wall
-Wextra
-Wpedantic
-Wconversion
-Wshadow
```

Warnings should be treated as defects rather than ignored.

---

## Code Quality

cForge uses several tools and practices to maintain code quality.

### Formatting

Source code is formatted using **clang-format**.

```bash id="pl9g0j"
clang-format -i src/*.c include/cforge/*.h
```

### Static Analysis

Static analysis can be performed using **clang-tidy**.

```bash id="g60pqs"
clang-tidy src/*.c -- -Iinclude
```

### Runtime Analysis

Memory-sensitive implementations should be tested with tools such as:

- AddressSanitizer
- UndefinedBehaviorSanitizer
- Valgrind
- GDB

---

## Development Workflow

cForge follows a lightweight **GitHub Flow** development model.

```text id="14xnil"
main
 │
 ├── feat/add-strlen
 ├── feat/add-memcpy
 ├── fix/memmove-overlap
 ├── test/strcmp-boundaries
 └── docs/build-instructions
```

Changes should generally be developed on focused branches and merged through pull requests.

### Commit Convention

cForge uses descriptive conventional-style commit messages.

```text id="t3jmnx"
feat(string): add string length implementation

feat(memory): add memory copy implementation

fix(memory): correct overlapping copy behavior

test(string): add empty string coverage

docs: clarify build instructions

ci: test builds with GCC and Clang
```

Keep commits focused on a single logical change whenever practical.

---

## Adding a Function

A typical workflow for implementing a new function is:

```text id="4u4bos"
1. Read the C specification or reference documentation
            ↓
2. Identify the function contract
            ↓
3. List important edge cases
            ↓
4. Write tests
            ↓
5. Implement the function
            ↓
6. Build with strict warnings
            ↓
7. Run unit tests
            ↓
8. Run sanitizers
            ↓
9. Run Valgrind when appropriate
            ↓
10. Review the implementation
            ↓
11. Open a pull request
```

For example:

```text id="8sr5xd"
Issue
  ↓
feat/add-strlen
  ↓
Implement strlen
  ↓
Add Criterion tests
  ↓
GCC + Clang
  ↓
ASan / UBSan
  ↓
Pull Request
  ↓
CI
  ↓
main
```

This workflow keeps each implementation small, testable, and reviewable.

---

## Example

An implementation in cForge may expose an interface similar to:

```c id="gyco5b"
#include <stddef.h>

size_t cforge_strlen(const char *str);
```

Usage:

```c id="14cip9"
#include <stdio.h>

#include <cforge/string.h>

int main(void)
{
    const char *message = "Hello, cForge!";

    printf("Length: %zu\n", cforge_strlen(message));

    return 0;
}
```

The specific API and naming conventions may evolve as the project develops.

---

## Documentation

Project documentation is kept under [`docs/`](docs/).

Useful documents include:

- [`docs/supported-functions.md`](docs/supported-functions.md) — implementation status
- [`docs/design.md`](docs/design.md) — architecture and design decisions
- [`CONTRIBUTING.md`](CONTRIBUTING.md) — contribution workflow
- [`SECURITY.md`](SECURITY.md) — vulnerability reporting
- [`CODE_OF_CONDUCT.md`](CODE_OF_CONDUCT.md) — community expectations

---

## Contributing

Contributions involving bug reports, additional test cases, documentation improvements, portability fixes, and code review are welcome.

Because implementing the library itself is an important part of the learning process, please open an issue before beginning a large implementation or major redesign.

Before submitting a pull request:

```bash id="5arhht"
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Also run the appropriate sanitizer or Valgrind checks for memory-sensitive changes.

See [`CONTRIBUTING.md`](CONTRIBUTING.md) for the complete contribution guidelines.

---

## Security

Memory errors in low-level C code can have security implications.

Potential security-related issues include:

- Out-of-bounds reads
- Out-of-bounds writes
- Incorrect allocation-size calculations
- Use-after-free behavior
- Unintended memory disclosure
- Undefined behavior with security implications

Please **do not disclose suspected vulnerabilities publicly** before giving the maintainer an opportunity to investigate them.

See [`SECURITY.md`](SECURITY.md) for the vulnerability reporting process.

---

## Why cForge?

Functions such as:

```c id="h9iaf5"
strlen()
memcpy()
memmove()
strcmp()
strtol()
qsort()
```

are easy to call but hide important implementation details involving:

- Pointer arithmetic
- Memory layout
- Aliasing
- Integer conversions
- Buffer boundaries
- Overlapping regions
- Function pointers
- Undefined behavior
- Performance tradeoffs
- API contracts

cForge exists to explore those details directly.

---

## Disclaimer

cForge is an independent educational project.

It is **not affiliated with, endorsed by, or intended to replace** any existing C library implementation.

The project aims to reproduce behavior specified by applicable C standards where practical, but it should not be relied upon for production or security-critical software.

---

## License

This project is distributed under the terms described in [`LICENSE`](LICENSE).

---

<div align="center">

### cForge

**C Standard Library Reimplementation**

Built to understand C from the inside out.

</div>
