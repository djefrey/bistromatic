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
    for (int i = 0; base[i] != '\0'; i++) {
        if (contains_char(base[i], &base[i+1]))
            return (1);
    }
    for (int i = 0; operators[i] != '\0'; i++) {
        if (contains_char(operators[i], &operators[i+1]))
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

static char valid_op(char *expr, char *base, char *ops)
{
    char prev;
    char next;

    for (int i = 0; expr[i]; i++) {
        if ((expr[i] == MULT_OP(ops) || expr[i] == DIV_OP(ops))
        || (expr[i] == MOD_OP(ops))) {
            prev = expr[i - 1];
            next = expr[i + 1];
            if ((!contains_char(prev, base) && prev != CLOSE_PAR(ops))
            || (!contains_char(next, base) && next != OPEN_PAR(ops)
            && next != SUB_OP(ops)))
                return (1);
            else if (expr[i + 1] == '\0' || expr[i] == expr[0])
                return (1);
        }
    }
    return (0);
}

static char check_unknown(char *expr, char *base, char *ops)
{
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '\n' && expr[i + 1] == '\0')
            return (0);
        else if (!contains_char(expr[i], base) && !contains_char(expr[i], ops))
            return (1);
    }
    return (0);
}

char check_error(char *expr, char *base, char *operators)
{
    int error = 0;

    error += check_unknown(expr, base, operators);
    error += valid_base_ops(base, operators);
    error += valid_brackets(expr, operators);
    error += valid_op(expr, base, operators);
    error += my_strlen(expr) == 0;
    error += my_strlen(expr) == 1 && *expr == '\n';
    return (error);
}