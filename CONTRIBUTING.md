# Contributing to cForge

cForge is a personal C standard library implementation project focused on
learning C, understanding library behavior, and practicing maintainable software
development. Contributions that improve correctness, testing, documentation,
and portability are welcome.

Because implementing the functions is part of the learning process, please
open an issue before submitting a large implementation or starting a major
redesign. Bug reports, additional test cases, and code reviews are especially
helpful.

## Getting started

- Read the README for the current project scope and setup instructions.
- Follow the documented build and test commands. Include any additional steps
  needed to reproduce your results in your pull request.
- Check existing issues and pull requests before starting work.
- Fork the repository if you do not have write access, then create a branch
  from an up-to-date copy of the default branch.

Use a short branch name that describes the change, for example:

```text
feat/add-strlen
fix/memmove-overlap
test/strcmp-boundary-cases
docs/build-instructions
```

## Reporting bugs

Include the affected function, a minimal reproducer, expected behavior, and
actual behavior. Also provide the commit or version tested, operating system,
compiler version, and relevant compiler flags.

If a test or diagnostic tool reports the problem, include its command and
relevant output. Explain which documented behavior the implementation violates.

## Proposing functions or other changes

Describe the problem or missing functionality, the intended behavior, and how
the change fits the project's scope. Identify the applicable C standard or
other specification when relevant, along with useful acceptance tests.

Discuss changes to public interfaces, dependencies, build tools, or overall
architecture before implementing them.

## Coding guidelines

- Match the surrounding code's naming, formatting, and file organization. Use
  the repository's formatter configuration when one is provided.
- Use the C language standard selected by the project. Discuss compiler-specific
  extensions or platform dependencies before introducing them.
- Keep changes focused. Submit unrelated cleanup and broad formatting changes
  separately.
- Prioritize clear, correct behavior before optimization. Explain non-obvious
  choices in comments, including relevant assumptions and constraints.
- Follow each function's documented contract. Document intentional deviations
  from standard library behavior instead of adding them silently.
- Keep generated files, build outputs, and editor-specific settings out of
  commits unless the project explicitly tracks them.

## Testing changes

Add tests for new behavior and a regression test for a bug fix when practical.
Use the existing test framework and cover relevant normal inputs, boundaries,
return values, and effects on memory.

Compare results with the system's C library only for inputs with defined
behavior, and compare what the specification actually guarantees. For example,
comparison functions may guarantee a result's sign without guaranteeing its
exact magnitude.

Run the relevant tests and, when available, the full suite. For memory-related
changes, use AddressSanitizer, UndefinedBehaviorSanitizer, or Valgrind as
appropriate. Run Valgrind separately from sanitizer-instrumented builds.
Portability changes should be checked with another supported compiler or
platform when available.

If a check cannot be run, explain the limitation in the pull request. If no
automated harness exists for the affected code yet, include a reproducible test
program and its build/run commands.

## Pull requests

Keep each pull request focused on one feature, bug fix, or related improvement.
Include:

- The problem being addressed and a related issue, if one exists.
- A brief explanation of the changes and relevant design decisions.
- The tests and diagnostic checks performed, with their results.
- Any compatibility changes, limitations, or follow-up work.

Update documentation when behavior, setup, or public interfaces change. Review
the diff before submitting and make sure it contains only intended changes.
Address review feedback and resolve failures in any configured checks before
merging; explain pre-existing or unrelated failures.

Use descriptive commit messages. These prefixes are a useful convention:

```text
feat(string): implement strcmp
feat(memory): implement memmove
fix(string): correct strncpy padding
test(memory): cover overlapping buffers
docs: update build instructions
```

Small documentation corrections can go directly to a pull request without a
separate issue.

## Conduct and licensing

Follow the repository's code of conduct. Keep feedback respectful, specific,
and focused on the work.

Submit work you have the right to contribute under the project's license.
Identify any adapted third-party material and preserve its required notices.
Be prepared to explain and maintain the code you submit.
