# 🚀 TODO: cForge Development Roadmap

This file outlines the planned features, improvements, and future goals for `cForge`. Contributions and suggestions are welcome! See [`CONTRIBUTING.md`](CONTRIBUTING.md) for how to help.

---

## ✅ Phase 1: Standard C Function Reimplementation (In Progress)

### 📌 1. Standard I/O Functions (`stdio.h`)
- [ ] `FILE *fopen(const char *filename, const char *mode);`
- [ ] `int fclose(FILE *stream);`
- [ ] `size_t fread(void *ptr, size_t size, size_t count, FILE *stream);`
- [ ] `size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);`
- [ ] `int fprintf(FILE *stream, const char *format, ...);`
- [ ] `int fscanf(FILE *stream, const char *format, ...);`
- [ ] `int printf(const char *format, ...);`
- [ ] `int scanf(const char *format, ...);`
- [ ] `int putchar(int character);`
- [ ] `int getchar(void);`
- [ ] `char *fgets(char *str, int n, FILE *stream);`
- [ ] `int feof(FILE *stream);`
- [ ] `int fseek(FILE *stream, long offset, int whence);`
- [ ] `long ftell(FILE *stream);`
- [ ] `void rewind(FILE *stream);`
- [ ] `int fflush(FILE *stream);`

✅ **Custom Additions (`file_utils.h`)**
- [ ] `int file_exists(const char *filename);`
- [ ] `size_t get_file_size(const char *filename);`
- [ ] `char *read_file_to_string(const char *filename);`
- [ ] `void write_string_to_file(const char *filename, const char *content);`
- [ ] `int dir_create(const char *dirname);`
- [ ] `int dir_remove(const char *dirname);`

---

### 📌 2. String Manipulation (`string.h`)
- [ ] `size_t strlen(const char *s);`
- [ ] `char *strcpy(char *dest, const char *src);`
- [ ] `char *strncpy(char *dest, const char *src, size_t n);`
- [ ] `char *strcat(char *dest, const char *src);`
- [ ] `char *strncat(char *dest, const char *src, size_t n);`
- [ ] `char *strchr(const char *s, int c);`
- [ ] `char *strrchr(const char *s, int c);`
- [ ] `char *strstr(const char *haystack, const char *needle);`
- [ ] `int strcmp(const char *s1, const char *s2);`
- [ ] `int strncmp(const char *s1, const char *s2, size_t n);`
- [ ] `char *strdup(const char *s);`
- [ ] `char *strtok(char *str, const char *delim);`

✅ **Custom Additions (`string_utils.h`)**
- [ ] `size_t strcount(const char *s, char c);`
- [ ] `char *strreplace(char *s, char old, char new);`
- [ ] `char **strsplit(const char *s, char delim, int *count);`
- [ ] `char *strtrim(char *s);`
- [ ] `char *strreverse(char *s);`
- [ ] `char *strupper(char *s);`
- [ ] `char *strlower(char *s);`

---

### 📌 3. Memory Management (`stdlib.h`)
- [ ] `void *malloc(size_t size);`
- [ ] `void *calloc(size_t num, size_t size);`
- [ ] `void *realloc(void *ptr, size_t new_size);`
- [ ] `void free(void *ptr);`

✅ **Custom Additions (`memory_utils.h`)**
- [ ] `void *safe_malloc(size_t size);`
- [ ] `void safe_free(void *ptr);`
- [ ] `void *safe_realloc(void *ptr, size_t new_size);`
- [ ] `void hexdump(const void *ptr, size_t size);`

---

### 📌 4. Math Functions (`math.h`)
- [ ] `double sqrt(double x);`
- [ ] `double pow(double x, double y);`
- [ ] `double sin(double x);`
- [ ] `double cos(double x);`
- [ ] `double tan(double x);`
- [ ] `double log(double x);`
- [ ] `double log10(double x);`
- [ ] `double ceil(double x);`
- [ ] `double floor(double x);`

✅ **Custom Additions (`math_utils.h`)**
- [ ] `double fast_sqrt(double x);`
- [ ] `double fast_pow(double x, double y);`

---

### 📌 5. Process Management (`sys_utils.h`)
- [ ] `pid_t fork(void);`
- [ ] `pid_t getpid(void);`
- [ ] `pid_t getppid(void);`
- [ ] `int execve(const char *filename, char *const argv[], char *const envp[]);`
- [ ] `int system(const char *command);`
- [ ] `void exit(int status);`

✅ **Custom Additions**
- [ ] `int get_pid_by_name(const char *process_name);`
- [ ] `void kill_process(int pid);`
- [ ] `void system_reboot();`
- [ ] `void system_shutdown();`

---

### 📌 6. Networking (`net_utils.h`)
- [ ] `int socket(int domain, int type, int protocol);`
- [ ] `int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`
- [ ] `int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`
- [ ] `int listen(int sockfd, int backlog);`
- [ ] `int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);`
- [ ] `ssize_t send(int sockfd, const void *buf, size_t len, int flags);`
- [ ] `ssize_t recv(int sockfd, void *buf, size_t len, int flags);`

✅ **Custom Additions**
- [ ] `char *http_get(const char *url);`
- [ ] `char *http_post(const char *url, const char *data);`
- [ ] `int tcp_connect(const char *host, int port);`
- [ ] `void tcp_send(int socket, const char *data);`
- [ ] `char *tcp_receive(int socket);`

---

### 📌 7. Cryptography (`crypto_utils.h`)
- [ ] `void sha256(const char *data, size_t len, char *output);`
- [ ] `char *base64_encode(const char *input, size_t len);`
- [ ] `char *base64_decode(const char *input, size_t len);`
- [ ] `void xor_encrypt(char *data, const char *key, size_t len);`
- [ ] `void xor_decrypt(char *data, const char *key, size_t len);`

---

### 📌 8. Debugging & Logging (`debug_utils.h`)
- [ ] `void log_message(int level, const char *format, ...);`
- [ ] `void hexdump(const void *ptr, size_t size);`

---

### 📌 9. Task Scheduling (`automation_utils.h`)
- [ ] `void add_task(void (*func)(void *), void *arg, uint32_t interval);`
- [ ] `void run_scheduler();`
- [ ] `int run_background_job(const char *command);`
- [ ] `void auto_restart_process(const char *process_name);`

---
