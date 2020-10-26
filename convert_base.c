/*
** EPITECH PROJECT, 2020
** convert_base
** File description:
** convert a number in a string into a given base
*/

#include <stdlib.h>
#include "infinop.h"

static int get_dec_to_base_len(int nbr, char *base, int base_size)
{
    int quotient = nbr;
    int remainder = 0;
    int length = 0;

    if (nbr < 0) {
        nbr *= -1;
        quotient *= -1;
    }
    while (quotient > 0) {
        quotient = nbr / base_size;
        remainder = nbr - quotient * base_size;
        nbr = quotient;
        length++;
    }
    return (length);
}

char *convert_base_to_dec(char *nb, char *base, int size)
{
    int base_size = my_strlen(base);
    int factor = 0;
    int index = 0;
    char *mult;
    char *str = malloc(sizeof(char) * (size + 1));

    my_fillstr(str, '0', size + 1);
    for (int i = 0; i < size; i++) {
        factor = my_compute_power_it(base_size, size - i - 2);
        for (int j = 0; j < base_size; j++) {
            if (base[j] == nb[i]) {
                index = j;
                break;
            }
        }
        mult = infinmult(my_intstr(index), my_intstr(factor));
        str = infinadd(str, mult);
    }
    return (str);
}

char *convert_dec_to_base(int nbr, char *base)
{
    int base_size = my_strlen(base);
    int quotient = nbr;
    int remainder = 0;
    int length = get_dec_to_base_len(nbr, base, base_size);
    char *str = malloc(sizeof(char) * (length + 1));
    int i = 0;

    /*if (is_nbr_neg(nbr)) {
        nbr *= -1;
        quotient *= -1;
    }*/
    while (quotient > 0) {
        quotient = nbr / base_size;
        remainder = nbr - quotient * base_size;
        str[length - 1 - i] = base[remainder];
        nbr = quotient;
        i++;
    }
    str[length] = '\0';
    return (str);
}