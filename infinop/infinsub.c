/*
** EPITECH PROJECT, 2020
** infinsub
** File description:
** infinsub
*/

#include <stdlib.h>
#include "infinop.h"
#include "my.h"

char *infinsub(char *nb1, char *nb2)
{
    int len2 = my_strlen(nb2);
    char *new_nb2;
    char *result;
    char need_free = 0;

    if (*nb2 == '-') {
        new_nb2 = nb2 + 1;
    } else {
        new_nb2 = malloc(sizeof(char) * (len2 + 2));
        new_nb2[0] = '-';
        my_strcat(new_nb2, nb2);
        need_free = 1;
    }
    result = infinadd(nb1, new_nb2);
    if (need_free)
        free(new_nb2);
    return (result);
}