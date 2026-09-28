# Design Notes

These are the initial design decisions for cForge. No library code or test
harness is implemented yet. Update this document when a decision changes;
record significant tradeoffs in the related issue or pull request.

## Purpose And Scope

cForge is an educational reimplementation of selected C standard library
functions. The initial goal is readable, correct implementations with documented
contracts and reproducible tests.

Start with string and memory operations, then character handling and integer
conversions. Allocation, formatted I/O, platform integration, and broader
standard-library coverage are deferred. The [Function Tracker](supported-functions.md)
records the current backlog.

## Language And Platform Targets

- Use C17 with compiler extensions disabled, as configured in `CMakeLists.txt`.
- Target hosted environments initially. Freestanding and bare-metal builds are
  future work, not current capabilities.
- The existing CI checks the build setup with GCC and Clang on Ubuntu and MSVC
  on Windows. No function-level portability has been demonstrated yet.
- Do not assume pointer width, integer width, alignment, or endianness. Use
  appropriate standard types and document any unavoidable assumptions.
- The initial character-classification scope is the C locale on ASCII-compatible
  execution character sets. Full locale handling and other execution character
  sets require separate design and tests.

## Public API And Planned Layout

Use `cforge_` names for public functions, such as
`size_t cforge_strlen(const char *str)`. This allows the implementation and the
host library to be linked into the same test program without replacing the
host's standard symbols.

The following paths are planned and will be created with their first contents:

| Location | Intended responsibility |
| --- | --- |
| `include/cforge/` | Public headers grouped by standard-library area |
| `src/string/` | String functions |
| `src/memory/` | Byte-oriented memory functions |
| `src/ctype/` | Character classification and conversion |
| `src/stdlib/` | Integer conversions and later utilities |
| `tests/` | Test sources and CMake test registration |

String and byte-memory APIs will share `include/cforge/string.h`, mirroring
where those interfaces are declared by the C standard library. Public headers
should include the standard type headers they need, compile independently, and
use include guards such as `CFORGE_STRING_H`.

Internal helpers should have internal linkage where practical. The first build
target is planned as a static library; installation and packaging come later.

## Dependencies And Implementation Boundaries

Use platform-provided definitions from headers such as `<stddef.h>`,
`<stdint.h>`, and `<limits.h>`. Reimplementing these type and limit headers is
outside the initial scope.

Implement each function's behavior directly. A cForge function must not delegate
its central operation to the corresponding host-libc function. Reusing an
already tested cForge helper is acceptable.

Tests and example programs may use the host library for fixtures, output, and
comparisons. Criterion is the planned test framework and should remain a
test-only dependency. It has not been integrated or validated against the
entire CI matrix; confirm the Windows test setup when adding the harness.

Integer conversions will need documented handling for range errors and `errno`.
Choose that integration before implementing them. Allocation and I/O will need
separate decisions about operating-system dependencies.

## Function Contracts And Correctness

Preserve the relevant C17 behavior wherever the documented scope supports it.
Document any intentional restriction or deviation alongside the affected API.

- Use `size_t` for sizes and counts where the standard interface does.
- Treat object representations as bytes using appropriate character types.
- Respect overlap rules: `memmove` accepts overlapping regions; `memcpy` does not.
- Do not assume string or byte comparison functions return exactly `-1` or `1`.
- Do not add silent recovery behavior for inputs outside the function contract.
  For example, `strlen(NULL)` is not a defined standard-library test case.
- A zero count does not automatically make invalid pointers acceptable. Check
  the contract of each function before creating boundary tests.

Prefer a straightforward implementation first. Optimizations need evidence,
additional boundary tests, and a clear explanation of their assumptions.

## Testing Approach

CTest will run the planned Criterion test executables. Register the first real
tests with the first function; merely enabling CTest does not create tests.

Test normal cases, defined boundary cases, return values, and effects on memory.
Include overlapping-buffer cases where supported and sentinel bytes around
valid destination regions where useful. Add a regression test for each fixed
behavioral defect.

Host-library comparisons are useful only for defined inputs under compatible
locale and platform conditions. Compare the properties the specification
promises, such as a comparison result's sign, instead of incidental values.

Add AddressSanitizer and UndefinedBehaviorSanitizer checks as the harness is
introduced. Run Valgrind separately on an appropriate non-sanitized build.
These checks are planned; the current CI does not run them.

## Build And Formatting

CMake is the primary build system, with a minimum version of 3.20. Use
`CMAKE_BUILD_TYPE` when configuring single-configuration generators and
`--config` when building with multi-configuration generators.

The checked-in `.clang-format` uses the LLVM base style, four-space indentation,
100-column lines, pointer stars next to variable names, and opening braces on
the same line. Formatting is not currently enforced by CI.

When the first library target is added, attach include paths and compiler
warnings to that target. Add portable compiler-specific warning options then,
and keep test and sanitizer settings separate from consumers of the library.
