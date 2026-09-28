# Function Tracker

No functions are implemented yet. This is the initial backlog, not a claim of
complete C17 library coverage. Every function below has **Planned** status and no
registered tests.

Names in the tables are standard-library names. The planned cForge API uses a
`cforge_` prefix; for example, `strlen` becomes `cforge_strlen`.

## Status Definitions

| Status | Meaning |
| --- | --- |
| Planned | Not implemented or tested |
| In progress | Implementation or tests are being developed |
| Implemented | Implementation and tests are merged and pass the configured checks; limitations are documented |
| Deferred | Outside the current milestone; no delivery commitment |

Update a function's status in the same pull request as its implementation or
behavior change. If functions in a grouped row progress separately, split that
row so the status stays accurate.

## First Milestone: Strings And Memory

All of these functions correspond to `<string.h>` functionality.

| Function(s) | Status | Important behavior to cover |
| --- | --- | --- |
| `strlen` | Planned | Empty strings, embedded null terminators, and longer valid strings |
| `memset` | Planned | Fill-byte conversion, byte count, return pointer, and surrounding bytes |
| `memcpy` | Planned | Non-overlapping copies, byte count, and return pointer |
| `memmove` | Planned | Overlap in both directions, identical regions, and return pointer |
| `memcmp` | Planned | Unsigned-byte comparison, first difference, and result sign |
| `memchr` | Planned | First matching byte, absent byte, and search length |
| `strcmp`, `strncmp` | Planned | Unsigned-character ordering, prefixes, result sign, and length limits |
| `strcpy`, `strncpy` | Planned | Terminators, padding for `strncpy`, and destination capacity |
| `strcat`, `strncat` | Planned | Appending, count semantics, terminators, and destination capacity |
| `strchr`, `strrchr` | Planned | First/last match and searches for the terminating null character |
| `strstr` | Planned | Empty needle, matching prefixes, repeated characters, and absent matches |
| `strspn`, `strcspn`, `strpbrk` | Planned | Empty character sets and stopping at the correct character |

Start with `cforge_strlen`. The other rows are a backlog, not a required
implementation order.

## Next Milestone: Character Handling

These functions correspond to `<ctype.h>` functionality. Initial scope is the
C locale on platforms with an ASCII-compatible execution character set.
Full locale support is deferred and must not be implied by the API docs.

| Function(s) | Status | Important behavior to cover |
| --- | --- | --- |
| `isalnum`, `isalpha`, `isdigit`, `isxdigit` | Planned | Classification boundaries and zero/nonzero results |
| `islower`, `isupper`, `tolower`, `toupper` | Planned | Case boundaries, unchanged values, and conversions |
| `isspace`, `isblank`, `iscntrl` | Planned | Distinct whitespace/control categories |
| `isprint`, `isgraph`, `ispunct` | Planned | Spaces, punctuation, and printable-character boundaries |

The planned input contract follows the C interfaces: `EOF` or a value
representable as `unsigned char`. Do not use other negative values as
host-libc comparison tests.

## Later Milestone: Integer Conversions

These functions correspond to `<stdlib.h>` functionality.

| Function(s) | Status | Important behavior to cover |
| --- | --- | --- |
| `strtol`, `strtoul`, `strtoll`, `strtoull` | Planned | Base selection, signs, end pointers, limits, and range errors |
| `atoi`, `atol`, `atoll` | Planned | Valid inputs with representable results; no invented overflow guarantees |

Integer conversions require an explicit error-handling design before
implementation. Floating-point conversions are deferred.

## Deferred Scope

Allocation (`malloc`, `calloc`, `realloc`, `free`), formatted I/O and streams,
searching and sorting (`bsearch`, `qsort`), locale and wide-character support,
and floating-point conversions are outside the first milestones.

The initial library will use platform headers such as `<stddef.h>` and
`<stdint.h>` for types instead of providing replacement standard headers.
This tracker will grow as the project scope becomes clearer.

## Completion Checklist

Before marking a function **Implemented**:

- Declare its public interface and document its contract and any limitations.
- Build its implementation as part of the cForge library target.
- Add tests and register the test executable with CTest.
- Cover normal inputs, defined boundary cases, return values, and memory effects.
- Compare with the host library only where the specification defines the behavior.
- Run the configured compiler checks and the relevant available memory checks.
- Include reproducible commands and results in the pull request.

Until the test harness and build target exist, all functions remain Planned.
