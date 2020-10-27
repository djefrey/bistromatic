/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** errors managment
*/

#include "my.h"
#include "operators.h"
#include "bistromatic.h"

static char valid_base_ops(char *base, char *operators)
{
    int base_len = my_strlen(base);
    int op_len = my_strlen(operators);

    if (base_len < 2 || op_len != 7)
        return (1);
    for (int i = 0; i < base_len; i++) {
        if (contains_char(base[i], operators))
            return (1);
    }
    return (0);
}

static char valid_brackets(char *expr, char *operators)
{
    int expr_len = my_strlen(expr);
    int open_brackets = 0;

    for (int i = 0; i < expr_len; i++) {
        if (expr[i] == OPEN_PAR(operators))
            open_brackets++;
        else if (expr[i] == CLOSE_PAR(operators))
            open_brackets--;
    }
    return (open_brackets != 0);
}

char check_error(char *expr, char *base, char *operators)
{
    int error = 0;

    error += valid_base_ops(base, operators);
    error += valid_brackets(expr, operators);
    return (error > 0);
}