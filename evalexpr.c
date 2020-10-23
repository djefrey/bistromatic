/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** evalexpr file
*/

#include <stdlib.h>
#include "my.h"
#include "evalexpr.h"

char *number(char **str_ptr)
{
    char *nbr;
    int len = 0;

    if (**str_ptr == '-')
        len++;
    while (is_digit(*(*str_ptr + len)))
        len++;
    nbr = malloc(sizeof(char) * (len + 1));
    my_fillstr(nbr, '0', len);
    my_strncpy(nbr, *str_ptr, len);
    *str_ptr += len;
    return (nbr);
}

char *brackets(char **str_ptr)
{
    char *result;

    if (**str_ptr == '(') {
        *str_ptr += 1;
        result = summands(str_ptr);
        if (**str_ptr == ')')
            *str_ptr += 1;
    } else if (**str_ptr == ')') {
        *str_ptr += 1;
        result = number(str_ptr);
    } else {
        result = number(str_ptr);
    }
    return (result);
}

char *factors(char **str_ptr)
{
    char *factor = brackets(str_ptr);
    char sign = -1;

    while (**str_ptr == '*' || **str_ptr == '/' || **str_ptr == '%') {
        sign = **str_ptr;
        *str_ptr += 1;
        if (sign == '*')
            factor = infinmult(factor, brackets(str_ptr));
        else if (sign == '/')
            factor = infindiv(factor, brackets(str_ptr));
        else
            factor = infinmod(factor, brackets(str_ptr));
    }
    return (factor);
}

char *summands(char **str_ptr)
{
    char *sum = factors(str_ptr);
    char sign = 0;

    while (**str_ptr == '+' || **str_ptr == '-') {
        sign = **str_ptr;
        *str_ptr += 1;
        if (sign == '+')
            sum = infinadd(sum, factors(str_ptr));
        else
            sum = infinsub(sum, factors(str_ptr));
    }
    return (sum);
}

char *eval_expr(char const *str)
{
    int len = my_strlen(str);
    char *expr = malloc(sizeof(char) * (len + 1));
    char *sum;
    int cursor = 0;
    int offset = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            expr[cursor] = str[i];
            cursor++;
        }
    }
    expr[cursor] = '\0';
    sum = summands(&expr);
    return (sum);
}