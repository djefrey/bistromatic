/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** utilities
*/

#include <stdlib.h>
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

void replace_ans_save_expr(char **expr, char *result, history_t **hist)
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
