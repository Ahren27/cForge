# Security Policy

cForge is a personal C standard library implementation project in active
development. Reports that help identify and fix security-relevant defects are
welcome.

## Supported code

During development, security fixes target the latest code on the repository's
default branch. Older commits and release versions do not receive separate
security updates unless explicitly announced.

Reports about older code are still welcome. Please include the affected commit
or version and indicate whether you can reproduce the issue on the latest code.

## Reporting a vulnerability

If the repository offers GitHub's **Report a vulnerability** option, use it to
submit a private report. This option is available through the repository's
security advisories when private vulnerability reporting is enabled.

If that option is unavailable, open an issue requesting a private security
contact. Keep that initial issue limited to the contact request; do not include
reproduction steps, exploit details, or sensitive information in a public issue
or pull request while arranging private disclosure.

In your private report, include:

- The affected function and commit or version.
- A description of the problem and its potential impact.
- A minimal reproducer and the commands needed to build and run it.
- Your operating system, architecture, compiler version, and relevant flags.
- Relevant test results or sanitizer output, if available.

Use synthetic test data rather than credentials or private application data.
A complete exploit is not required to report a suspected vulnerability.

## What to report

Examples include unintended reads or writes outside valid memory, allocation
size errors, unintended disclosure of memory contents, and implementation bugs
that could allow an application using cforge to be disrupted or compromised.

Explain the input conditions and the function's documented contract. Caller
misuse and implementation defects may require different fixes. If you are unsure
whether a problem has security implications, report it privately for discussion.

Ordinary documentation errors, feature requests, and bugs without suspected
security impact can be reported through public issues.

## Handling reports

Reports are reviewed on a best-effort basis. This personal project does not
guarantee a response or fix within a specific timeframe.

For a confirmed issue, the intended process is to reproduce the defect, assess
its impact, develop a fix, and add a regression test where practical. Any
necessary release notes or security advisory will describe affected code and
available fixes or mitigations.

Please coordinate public disclosure with the maintainer so the findings and
available remedies can be communicated accurately. Reporter credit can be
included with the reporter's permission.
