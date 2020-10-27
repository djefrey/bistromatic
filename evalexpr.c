/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** evalexpr
*/

#include <stdlib.h>
#include "my.h"
#include "evalexpr.h"
#include "infinop.h"
#include "operators.h"

char *number(char **str_ptr, char *base, char *ops)
{
    char *nbr;
    int len = 0;
    char *res;

    if (**str_ptr == SUB_OP(ops))
        len++;
    while (contains_char(*(*str_ptr + len), base))
        len++;
    nbr = malloc(sizeof(char) * (len + 1));
    my_fillstr(nbr, '0', len);
    my_strncpy(nbr, *str_ptr, len);
    *str_ptr += len;
    res = convert_base_to_dec(nbr, base, len);
    return (res);
}

char *brackets(char **str_ptr, char *base, char *ops)
{
    char *result;

    if (**str_ptr == OPEN_BRACKET(ops)) {
        *str_ptr += 1;
        result = summands(str_ptr, base, ops);
        if (**str_ptr == CLOSE_BRACKET(ops))
            *str_ptr += 1;
    } else if (**str_ptr == SUB_OP(ops) && *(*str_ptr + 1) == OPEN_BRACKET(ops)) {
        *str_ptr += 2;*
        // A CHNAGER
        result = infinsub("0", summands(str_ptr, base, ops));
        if (**str_ptr == CLOSE_BRACKET(ops))
            *str_ptr += 1;
    } else
        result = number(str_ptr, base, ops);
    return (result);
}

char *factors(char **str_ptr, char *base, char *ops)
{
    char *factor = brackets(str_ptr, base, ops);
    char sign = -1;

    while (**str_ptr == MULT_OP(ops) || **str_ptr == DIV_OP(ops) || **str_ptr == MOD_OP(ops)) {
        sign = **str_ptr;
        *str_ptr += 1;
        if (sign == MULT_OP(ops))
            factor = infinmult(factor, brackets(str_ptr, base, ops));
        else if (sign == DIV_OP(ops))
            factor = infindiv(factor, brackets(str_ptr, base, ops));
        else
            factor = infinmod(factor, brackets(str_ptr, base, ops));
    }
    return (factor);
}

char *summands(char **str_ptr, char *base, char *ops)
{
    char *sum = factors(str_ptr, base, ops);
    char sign = 0;

    while (**str_ptr == ADD_OP(ops) || **str_ptr == SUB_OP(ops)) {
        sign = **str_ptr;
        *str_ptr += 1;
        if (sign == ADD_OP(ops))
            sum = infinadd(sum, factors(str_ptr, base, ops));
        else
            sum = infinsub(sum, factors(str_ptr, base, ops));
    }
    return (sum);
}

char *eval_expr(char const *str, char *base, char *ops)
{
    int len = my_strlen(str);
    char *expr = malloc(sizeof(char) * (len + 1));
    char *sum;
    int cursor = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            expr[cursor] = str[i];
            cursor++;
        }
    }
    expr[cursor] = '\0';
    sum = summands(&expr, base, ops);
    return (sum);
}