/*
** EPITECH PROJECT, 2020
** convert_base
** File description:
** convert a number in a string into a given base
*/

#include <stdlib.h>
#include "infinop.h"

static int get_dec_to_base_len(char *nb, char *base, char *base_size_str)
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
    int factor = 0;
    int index = 0;
    char *mult;
    char *str = malloc(sizeof(char) * 2);

    my_fillstr(str, '0', 1);
    for (int i = 0; i < nb_len; i++) {
        factor = my_compute_power_it(base_size, nb_len - i - 1);
        for (int j = 0; j < base_size; j++) {
            if (base[j] == nb[i]) {
                index = j;
                break;
            }
        }
        mult = infinmult(my_intstr(index), my_intstr(factor));
        str = infinadd(str, mult);
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
    int length = get_dec_to_base_len(nb, base, base_size_str);
    char *str = malloc(sizeof(char) * (length + 1));
    char *result = str;

    if (*nb == '-')
        quotient += 1;
    while (*quotient != '-' && !(*quotient == '0' && *(quotient + 1) == 0)) {
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