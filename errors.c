/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** errors managment
*/

#include "my.h"
#include "operators.h"

static char valid_base_ops(char *base, char *operators)
{
    int base_len = my_strlen(base);
    int op_len = my_strlen(operators);

    if (base_len < 2 || op_len != 7)
        return (0);
    for (int i = 0; i < base_len) {
        for (int j = 0; j < op_len; j++) {
            if (base[i] == op[j])
                return (0);
        }
    }
    return (1);
}

static char valid_brackets(char *expr, char *operators)
{
    int expr_len = my_strlen(expr);
    int open_brackets = 0;

    for (int i = 0; i < expr_len; i++) {
        if (expr[i] == OPEN_BRACKETS(operators))
            open_brackets++;
        else if (expr[i] == CLOSE_BRACKETS(operators))
            open_brackets--;
    }
    return (open_brackets == 0);
}

static char check_div_by_zero(char *expr, char *base, char *operators)
{
    int expr_len = my_strlen(expr);

    for (int i = 0; i < expr_len; i++) {
        if (expr[i] == DIV_OP(operators) && expr[i + 1] == base[0])
            return(0);
    }
    return (1);
}

char check_error(char *expr, char *base, char *operators)
{
    if (!valid_base_ops(base, operators) || !valid_brackets(expr, operators))
        return (1);
    else if (check_div_by_zero(expr, base, operators))
        return (1);
    return (0);
}