/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** main file for infinadd
*/

#include <stdlib.h>
#include "my.h"
#include "operations.h"

static char switch_bigger_n_first(char **nb1, char **nb2, int *len1, int *len2)
{
    *len1 = *nb1[0] == '-' ? my_strlen(*nb1) - 1 : my_strlen(*nb1);
    *len2 = *nb2[0] == '-' ? my_strlen(*nb2) - 1 : my_strlen(*nb2);

    my_revstr(*nb1);
    my_revstr(*nb2);
    if (*len2 > *len1) {
        my_strswap(nb1, nb2);
        my_intswap(len1, len2);
    } else if (*len1 == *len2 && my_strcmp(*nb1, *nb2) > 0) {
        my_strswap(nb1, nb2);
        my_intswap(len1, len2);
    }
    return (*(*nb1 + *len1) == '-' ? -1 : 1);
}

static char *remove_zeros(char *result)
{
    char neg = *result == '-';

    if (neg)
        result = result + 1;
    while (*result == '0' && *(result + 1) != '\0')
        result += 1;
    if (neg && *(result) != '0') {
        result -= 1;
        *result = '-';
    }
    return (result);
}

static char *finish_calc(char *result, char *nbrs[], int carry, char sign)
{
    int len1 = my_strlen(nbrs[0]);
    int len2 = my_strlen(nbrs[1]);
    char neg = (nbrs[0][len1 - 1] == '-' && nbrs[1][len2 - 1] == '-');

    if (carry >= 0) {
        result[1] = 48 + carry;
        if (neg || sign == -1)
            result[0] = '-';
        else
            result = (result + 1);
    } else {
        if (neg || sign == -1) {
            result[1] = '-';
            result = (result + 1);
        } else 
            result = (result + 2);
    }
    result = remove_zeros(result);
    return (result);
}

static char *do_infinadd(char *nbrs[], int lens[], add_fct_t op, char sign)
{
    char c1 = 0;
    char c2 = 0;
    int carry = 0;
    int max_len = (lens[0] > lens[1] ? lens[0] : lens[1]);
    char *result = malloc(sizeof(char) * (max_len + 3));

    if (result == NULL)
        return (NULL);
    result[max_len + 2] = '\0';
    for (int i = 0; i < max_len; i++) {
        c1 = (i < lens[0] ? nbrs[0][i] : '0');
        c2 = (i < lens[1] ? nbrs[1][i] : '0');
        result[max_len + 1 - i] = 48 + (*op)(c1, c2, &carry);
    }
    result = finish_calc(result, nbrs, carry, sign);
    return (result);
}

char *infinadd(char *nb1, char *nb2)
{
    add_fct_t op;
    int len1;
    int len2;
    char *strs[2];
    int lens[2];
    char sign = 0;
    char *result;

    nb1 = remove_zeros(my_strdup(nb1));
    nb2 = remove_zeros(my_strdup(nb2));
    sign = switch_bigger_n_first(&nb1, &nb2, &len1, &len2);
    strs[0] = nb1;
    strs[1] = nb2;
    lens[0] = len1;
    lens[1] = len2;
    op = get_addop(nb1[len1], nb2[len2]);
    result = do_infinadd(strs, lens, op, sign);
    free(nb1);
    free(nb2);
    return (result);
}