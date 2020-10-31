/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** utilities
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "bonus_ncurses.h"

static history_t *add_to_history(char *expr, char *result, history_t *prev)
{
    history_t *new = malloc(sizeof(history_t));

    new->expr = my_strdup(expr);
    new->result = my_strdup(result);
    new->prev = prev;
    return (new);
}

void replace_and_save_expr(char **expr, char *result, history_t **hist)
{
    *hist = add_to_history(*expr, result, *hist);
    free(*expr);
    *expr = my_strdup(result);
}

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

int get_space_base_square(int base_len, int *wsize, int *hsize)
{
    int space;
    int width;

    if (base_len < 4) {
        *wsize = 2;
        *hsize = base_len < 3 ? 1 : 2;
        space = 5;
    } else if (base_len <= 16) {
        *wsize = sqrt(base_len);
        if (*wsize * *wsize == base_len)
            *hsize = *wsize;
        else
            *hsize = *wsize +
            ceil((base_len - *wsize * *wsize) / (float)(*wsize));
        space = 5;
    } else {
        space = 5 - (base_len - 16) / 15;
        *wsize = sqrt(base_len);
        width = space * *wsize / 5;
        if (*wsize * *wsize == base_len)
            *hsize = width;
        else
            *hsize = width +
            ceil((base_len - *wsize * *wsize) / (float)(*wsize));
    }
    return (space);
}