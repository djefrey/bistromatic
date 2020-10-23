/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** main file for evalexpr
*/

#include "my.h"

int main(int ac, char **av)
{
    char *result;

    if (ac == 2) {
        result = eval_expr(av[1]);
        my_putstr(result);
        my_putchar('\n');
        return (0);
    }
    return (84);
}