/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** infindiv
*/

#include <stdlib.h>
#include "my.h"
#include "operations.h"
#include "infinop.h"

static char is_first_bigger(char *nb1, char *nb2, int len1, int len2)
{
    if (len2 > len1)
        return (1);
    else if (len1 == len2 && my_strcmp(nb1, nb2) < 0)
        return (1);
    return (0);
}

static char get_sign(char **nb1, char **nb2)
{
    if (**nb1 == '-' && **nb2 == '-') {
        *nb1 += 1;
        *nb2 += 1;
        return (1);
    } else if (**nb1 == '-' || **nb2 == '-') {
        *nb1 += (**nb1 == '-');
        *nb2 += (**nb2 == '-');
        return (-1);
    } else
        return (1);
}

static void move_chars_to_left(char *str, char new_c)
{
    char c;

    while (*(str + 1) != '\0') {
        c = *(str + 1);
        if (c >= '0' && c <= '9') {
            *(str) = *(str + 1);
            str += 1;
        } else
            break;
    }
    *str = new_c;
    *(str + 1) = 0;
}

static void do_infindiv(char *nb1, char *nb2, int len1, char *quotient)
{
    char *carry = malloc(sizeof(char) * (len1 + 1));
    char div_res;
    int carry_size = 0;
    char *sub;

    my_fillstr(carry, '0', len1);
    for (int i = 0; i < len1; i++) {
        move_chars_to_left(carry, nb1[i]);
        carry_size++;
        div_res = div_op(carry, nb2);
        if (div_res > 0 || carry_size >= my_strlen(nb2) - 1 || i == len1 - 1) {
            move_chars_to_left(quotient, div_res);
            sub = infinsub(carry, infinmult(my_intstr(div_res - 48), nb2));
            carry_size = my_strlen(sub);
            for (int i = 0; i < len1 + 1; i++)
                carry[len1 - i] =
                (carry_size - 1 - i >= 0 ? sub[carry_size - 1 - i] : '0');
        }
    }
}

char *infindiv(char *nb1, char *nb2)
{
    char sign = get_sign(&nb1, &nb2);
    int len1 = my_strlen(nb1);
    int len2 = my_strlen(nb2);
    char *result = malloc(sizeof(char) * (len1 + 2));

    if (my_str_isfilled(nb2, '0'))
        return (NULL);
    if (is_first_bigger(nb1, nb2, len1, len2))
        return (my_strdup("0"));
    my_fillstr(result, '0', len1 + 1);
    do_infindiv(nb1, nb2, len1, result);
    while (*result == '0' && *(result + 1) != '\0')
        result += 1;
    if (sign == -1 && !(*result == '0' && *(result + 1) == '\0')) {
        result -= 1;
        *result = '-';
    }
    return (result);
}