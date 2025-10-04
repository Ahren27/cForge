# cForge ROADMAP.md — Standard C `<stdio.h>` Phase

## 🎯 Focus Scope
Rebuild and document **every function in `<stdio.h>`** as part of a learning and practice exercise in C programming.  
The goal is to understand how standard I/O functions work internally while keeping implementations correct, portable, and clear.  
This phase focuses on education and experimentation, not replacing libc.

---

## 📦 Version Milestones

| Version | Description | Target Functions |
|----------|--------------|------------------|
| **v0.1.0 – Core Output** | Implement base output routines to stdout and memory. | `putchar`, `puts`, `printf`, `vprintf`, `sprintf`, `snprintf`, `vsprintf`, `vsnprintf` |
| **v0.2.0 – Core Input** | Implement input handling without FILE streams for learning. | `getchar`, `scanf`, `sscanf`, `vscanf`, `vsscanf` |
| **v0.3.0 – File Operations** | Learn file lifecycle and buffering. | `fopen`, `freopen`, `fclose`, `fflush`, `setbuf`, `setvbuf` |
| **v0.4.0 – Binary I/O** | Study raw data reading, writing, and file positioning. | `fread`, `fwrite`, `fseek`, `ftell`, `rewind`, `fgetpos`, `fsetpos` |
| **v0.5.0 – Error Handling** | Implement stream error detection and diagnostics. | `clearerr`, `feof`, `ferror`, `perror` |
| **v0.6.0 – File Utilities** | Explore file management and temporary file creation. | `remove`, `rename`, `tmpfile`, `tmpnam` |

---

## 🧩 Implementation Order (Recommended)
1. Begin with the simplest output functions: `putchar` and `puts`.  
2. Create a basic `printf` system that supports `%s`, `%d`, `%x`, and `%f`.  
3. Add file lifecycle management functions: `fopen`, `fclose`, `fflush`.  
4. Implement binary I/O and file positioning.  
5. Finish with error reporting and file utility functions.  

---

## 📈 Progress Tracker
```md
[🟡] v0.1.0 – Core Output
[⬜] v0.2.0 – Core Input
[⬜] v0.3.0 – File Operations
[⬜] v0.4.0 – Binary I/O
[⬜] v0.5.0 – Error Handling
[⬜] v0.6.0 – File Utilities
```

---

## 🧠 Notes
- Each function should live in its own `.c` file under `src/stdio/` (for example, `src/stdio/fputs.c`).  
- Public headers are stored in `include/cforge/stdio/`.  
- Tests are written with Criterion under `tests/stdio/`.  
- Use optional debug builds with I/O tracing enabled through the `CF_DEBUG_IO` macro.  
- Focus on readability, correctness, and understanding — not optimization or feature completeness.
