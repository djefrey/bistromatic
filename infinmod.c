/*
** EPITECH PROJECT, 2020
** infinmod
** File description:
** infinmod
*/

#include "infinop.h"
#include "my.h"

char *infinmod(char *nb1, char *nb2)
{
    char *div = infindiv(nb1, nb2);
    int nb1_len = my_strlen(nb1);
    char *ten_factor = malloc(sizeof(char) * (nb1_len + 1));
    char mult;
    char sub;

    my_fillstr(ten_factor, '0', nb1_len);
    ten_factor[0] = '1';
    printf("%s(%i), %s\n", div, *div, ten_factor);
    mult = infinmult(div, ten_factor);
    printf("%s - %s\n", nb1, mult);
    sub = infinsub(nb1, mult);
    return (sub);
}