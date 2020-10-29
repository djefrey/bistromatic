/*
** EPITECH PROJECT, 2020
** convert_base
** File description:
** convert a number in a string into a given base
*/

#include <stdlib.h>
#include "infinop.h"
#include "my.h"

static char *my_compute_power_str(char *nb, int p)
{
    char *result = my_intstr(1);

    if (p == 0)
        return (result);
    else if (p < 0)
        return (my_intstr(0));
    for (int i = 0; i < p; i++)
        result = infinmult(result, nb);
    return (result);
}

static int get_dec_to_base_len(char *nb, char *base_size_str)
{
    char *quotient = nb;
    int length = 0;

    if (*nb == '-')
        quotient += 1;
    while (*quotient != '-' && !(*quotient == '0' && *(quotient + 1) == 0)) {
        quotient = infindiv(quotient, base_size_str);
        length++;
    }
    return (length);
}

char *convert_base_to_dec(char *nb, char *base)
{
    int nb_len = my_strlen(nb);
    int base_size = my_strlen(base);
    char *base_size_str = my_intstr(base_size);
    char *factor;
    int index = 0;
    char *str = malloc(sizeof(char) * 2);

    my_fillstr(str, '0', 1);
    for (int i = 0; i < nb_len; i++) {
        factor = my_compute_power_str(base_size_str, nb_len - i - 1);
        for (int j = 0; j < base_size; j++) {
            if (base[j] == nb[i]) {
                index = j;
                break;
            }
        }
        str = infinadd(str, infinmult(my_intstr(index), factor));
    }
    if (*nb == '-')
        str = infinsub(my_intstr(0), str);
    return (str);
}

char *convert_dec_to_base(char *nb, char *base)
{
    int base_size = my_strlen(base);
    char *base_size_str = my_intstr(base_size);
    char *quotient = nb;
    int remainder = 0;
    int length = get_dec_to_base_len(nb, base_size_str);
    char *str = malloc(sizeof(char) * (length + 1));
    char *result = str;

    if (*nb == '-')
        quotient += 1;
    while (*quotient != '-' && !my_str_isfilled(quotient, '0')) {
        remainder = my_getnbr(infinmod(quotient, base_size_str));
        quotient = infindiv(quotient, base_size_str);
        *str = base[remainder];
        str += 1;
    }
    my_revstr(result);
    if (*nb == '-')
        result = infinsub(my_intstr(0), result);
    return (result);
}