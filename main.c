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

int print_help(void)
{
    my_putstr("USAGE\n./calc base operators size_read\n");
    my_putchar('\n');
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the ");
    my_putstr("parentheses and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    return (0);
}

char *calculation(char **av)
{
    char *expr;
    int size;
    char *result;

    size = my_getnbr(av[3]);
    expr = malloc(sizeof(char) * size);
    read(0, expr, size);
    if (check_error(expr, av[1], av[2])) {
        write(2, SYNTAX_ERROR_MSG, 12);
        return (NULL);
    }
    result = eval_expr(expr, av[1], av[2]);
    if (result == NULL) {
        write(2, ERROR_MSG, 5);
        return (NULL);
    }
    if (my_strlen(av[1]) != 10 || my_strcmp(av[1], "0123456789") != 0)
        result = convert_dec_to_base(result, av[1]);
    if (*result == '-')
        *result = SUB_OP(av[2]);
    return (result);
}

int main(int ac, char **av)
{
    char *result;

    if (ac == 4) {
        result = calculation(av);
        if (result != NULL) {
            my_putstr(result);
            return (0);
        } else
            return (84);
    }
    else if (ac == 2 && my_strlen(av[1]) == 2 && my_strcmp(av[1], "-h") == 0)
        return (print_help());
    else {
        write(2, ERROR_MSG, 5);
        my_putchar('\n');
        return (84);
    }
}