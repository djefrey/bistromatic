/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** startup file
*/

#include <stdlib.h>
#include "my.h"
#include "operations.h"
#include "infinop.h"

static char are_valid_nbrs(char *n1, char *n2)
{
    int len1 = my_strlen(n1);
    int len2 = my_strlen(n2);

    for (int i = (n1[0] == '-' ? 1 : 0); i < len1; i++) {
        if (!is_digit(n1[i]))
            return (0);
    }
    for (int i = (n2[0] == '-' ? 1 : 0); i < len2; i++) {
        if (!is_digit(n2[i]))
            return (0);
    }
    return (1);
}

int main(int ac, char *av[])
{
    char *result;
    op_fct_t op = &infindiv;

    if (ac != 3 || !are_valid_nbrs(av[1], av[2]))
        return (84);
    // op = get_infinop(av[3]);
    result = (*op)(av[1], av[2]);
    if (result == NULL)
        return (84);
    my_putstr(result);
    my_putchar('\n');
    return(0);
}