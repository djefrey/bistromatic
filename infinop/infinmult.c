/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** infinmult
*/

#include <stdlib.h>
#include "my.h"
#include "operations.h"

static char get_sign(char *nb1, char *nb2)
{
    if (*nb1 == '-' && *nb2 == '-')
        return (1);
    else if (*nb1 == '-' || *nb2 == '-')
        return (-1);
    else
        return (1);
}

static void remove_zeros(char **result, char sign)
{
    while (**result == '0' && *(*result + 1) != '\0')
        *result += 1;
    if (sign == -1 && !(**result == '0' && *(*result + 1) == '\0')) {
        *result -= 1;
        **result = '-';
    }
}

static char *do_infinmult(char *nb1, char *nb2, int len1, int len2)
{
    int maxl = len1 + len2 + 1;
    char *res = malloc(sizeof(char) * (maxl + 1));
    int mult_car = 0;
    int add_car = 0;
    int mult = 0;

    my_fillstr(res, '0', maxl);
    for (int i = 0; i < len2; i++) {
        for (int j = 0; j < len1; j++) {
            mult = mult_op(nb1[j], nb2[i], &mult_car);
            res[maxl - 1 - j - i] =
            add_op(mult, res[maxl - 1 - j - i], &add_car);
        }
        if (mult_car > 0 || add_car > 0)
            res[maxl - 1 - len1 - i] =
            add_op(48 + mult_car, res[maxl - 1 - len1 - i], &add_car);
        add_car = 0;
        mult_car = 0;
    }
    return (res);
}

char *infinmult(char *nb1, char *nb2)
{
    char *cpy1;
    char *cpy2;
    char sign = get_sign(nb1, nb2);
    int len1 = (*nb1 == '-' ? my_strlen(nb1) - 1 : my_strlen(nb1));
    int len2 = (*nb2 == '-' ? my_strlen(nb2) - 1 : my_strlen(nb2));
    char *result;

    cpy1 = my_strdup(nb1);
    cpy2 = my_strdup(nb2);
    my_revstr(cpy1);
    my_revstr(cpy2);
    if (len2 > len1) {
        my_intswap(&len1, &len2);
        my_strswap(&cpy1, &cpy2);
    }
    result = do_infinmult(cpy1, cpy2, len1, len2);
    remove_zeros(&result, sign);
    free(cpy1);
    free(cpy2);
    return (result);
}