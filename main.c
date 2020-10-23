/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** main file for evalexpr
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "evalexpr.h"s

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
    result = eval_expr(expr);
    my_putstr(result);
    return (0);
}