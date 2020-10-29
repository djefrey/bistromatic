/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** utilities
*/

#include <stdlib.h>
#include "my.h"

char *add_ch(char *str, char c)
{
    int len = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (len + 2));

    my_strcpy(new_str, str);
    new_str[len] = c;
    new_str[len + 1] = 0;
    free(str);
    return (new_str);
}

char contains_char(char c, char *array)
{
    for (; *array != '\0'; array += 1) {
        if (*array == c)
            return (1);
    }
    return (0);
}
