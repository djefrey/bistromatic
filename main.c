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