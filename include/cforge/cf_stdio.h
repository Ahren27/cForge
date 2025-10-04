#ifndef CF_STDIO_H
#define CF_STDIO_H

// Standard C library includes
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Output */
int  cf_putchar(int c);
int  cf_puts(const char *s);
int  cf_fputs(const char *s, FILE *f);

int  cf_printf(const char *fmt, ...);
int  cf_fprintf(FILE *f, const char *fmt, ...);
int  cf_sprintf(char *dst, const char *fmt, ...);
int  cf_snprintf(char *dst, size_t n, const char *fmt, ...);
int  cf_vprintf(const char *fmt, va_list ap);
int  cf_vfprintf(FILE *f, const char *fmt, va_list ap);
int  cf_vsprintf(char *dst, const char *fmt, va_list ap);
int  cf_vsnprintf(char *dst, size_t n, const char *fmt, va_list ap);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CF_STDIO_H