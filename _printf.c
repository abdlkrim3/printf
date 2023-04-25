#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
    int sum = 0; /* variable to keep track of number of characters printed */
    va_list ap; /* variable argument list */
    char *p, *start; /* pointers to iterate over format string */
    params_t params = PARAMS_INIT; /* structure to store format specifier information */

    va_start(ap, format); /* initialize variable argument list */

    /* check for error conditions */
    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);

    /* iterate over each character in format string */
    for (p = (char *)format; *p; p++)
    {
        init_params(&params, ap); /* initialize params structure */
        if (*p != '%') /* if character is not a %, print it directly */
        {
            sum += _putchar(*p);
            continue;
        }
        start = p; /* save start position of format specifier */
        p++; /* move to next character */
        while (get_flag(p, &params)) /* while char at p is flag char */
        {
            p++; /* next char */
        }
        p = get_width(p, &params, ap); /* get width from format specifier */
        p = get_precision(p, &params, ap); /* get precision from format specifier */
        if (get_modifier(p, &params)) /* get length modifier from format specifier */
            p++;
        if (!get_specifier(p)) /* if no conversion specifier found, print characters as is */
            sum += print_from_to(start, p,
                params.l_modifier || params.h_modifier ? p - 1 : 0);
        else
            sum += get_print_func(p, ap, &params); /* get appropriate print function and call it */
    }
    _putchar(BUF_FLUSH); /* flush buffer */
    va_end(ap); /* clean up variable argument list */
    return (sum); /* return number of characters printed */
}
