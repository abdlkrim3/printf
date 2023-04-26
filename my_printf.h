#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>

typedef struct params_s
{
    /* define the fields of the params_t struct here */
    int l_modifier;
    int h_modifier;
} params_t;

#define PARAMS_INIT { /* initialize the fields of the params_t struct here */ }
#define BUF_FLUSH /* define the value of the BUF_FLUSH macro here */

void init_params(params_t *params, va_list ap);
int get_flag(const char *p, params_t *params);
const char *get_width(const char *p, params_t *params, va_list ap);
const char *get_precision(const char *p, params_t *params, va_list ap);
int get_modifier(const char *p, params_t *params);
int get_specifier(const char *p);
int print_from_to(const char *start, const char *stop, int mod);
int get_print_func(const char *p, va_list ap, params_t *params);

#endif /* MY_PRINTF_H */
