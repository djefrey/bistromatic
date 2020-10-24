/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** infinmod
*/

#include <stdlib.h>
#include "infinop.h"
#include "my.h"

char *infinmod(char *nb1, char *nb2)
{
    char *div = infindiv(nb1, nb2);
    int nb1_len = my_strlen(nb1);
    char *mult;
    char *sub;

    mult = infinmult(div, nb2);
    sub = infinsub(nb1, mult);
    return (sub);
}