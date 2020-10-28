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
#include "bistromatic.h"

char *number(char **str_ptr, char *base, char *ops)
{
    char *nbr;
    int len = 0;

    if (**str_ptr == SUB_OP(ops))
        len++;
    while (contains_char(*(*str_ptr + len), base))
        len++;
    nbr = malloc(sizeof(char) * (len + 1));
    my_fillstr(nbr, '0', len);
    my_strncpy(nbr, *str_ptr, len);
    *str_ptr += len;
    if (*nbr == SUB_OP(ops))
        *nbr = '-';
    if (my_strlen(base) != 10 || my_strcmp(base, "0123456789") != 0)
        nbr = convert_base_to_dec(nbr, base);
    return (nbr);
}

char *brackets(char **str_ptr, char *base, char *ops)
{
    char *result;
    char *null_str = malloc(sizeof(char) * 2);

    my_fillstr(null_str, base[0], 1);
    if (**str_ptr == OPEN_PAR(ops)) {
        *str_ptr += 1;
        result = summands(str_ptr, base, ops);
        if (**str_ptr == CLOSE_PAR(ops))
            *str_ptr += 1;
    } else if (**str_ptr == SUB_OP(ops) && *(*str_ptr + 1) == OPEN_PAR(ops)) {
        *str_ptr += 2;
        result = infinsub(null_str, summands(str_ptr, base, ops));
        if (**str_ptr == CLOSE_PAR(ops))
            *str_ptr += 1;
    } else
        result = number(str_ptr, base, ops);
    return (result);
}

char *factors(char **str_ptr, char *base, char *ops)
{
    char *factor = brackets(str_ptr, base, ops);
    char sign = -1;

    while ((**str_ptr == MULT_OP(ops) || **str_ptr == DIV_OP(ops)
    || **str_ptr == MOD_OP(ops)) && factor != NULL) {
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

    while ((**str_ptr == ADD_OP(ops) || **str_ptr == SUB_OP(ops))
    && sum != NULL) {
        sign = **str_ptr;
        *str_ptr += 1;
        if (sign == ADD_OP(ops))
            sum = infinadd(sum, factors(str_ptr, base, ops));
        else
            sum = infinsub(sum, factors(str_ptr, base, ops));
    }
    return (sum);
}

char *eval_expr(char *str, char *base, char *ops)
{
    char *sum;

    sum = summands(&str, base, ops);
    return (sum);
}