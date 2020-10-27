/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** main file
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "evalexpr.h"
#include "bistromatic.h"
#include "operators.h"

char contains_char(char c, char *array)
{
    for (; *array != '\0'; array += 1) {
        if (*array == c)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    char *expr;
    int size;
    char *result;

    if (ac != 4)
        return (84);
    size = my_getnbr(av[3]);
    expr = malloc(sizeof(char) * size);
    read(0, expr, size);
    if (check_error(expr, av[1], av[2])) {
        write(2, SYNTAX_ERROR_MSG, 12);
        return (84);
    }
    result = eval_expr(expr, av[1], av[2]);
    result = convert_dec_to_base(result, av[1]);
    if (*result == '-')
        *result = SUB_OP(av[2]);
    my_putstr(result);
    return (0);
}