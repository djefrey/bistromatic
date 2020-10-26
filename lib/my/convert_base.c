/*
** EPITECH PROJECT, 2020
** convert_base
** File description:
** convert a number in a string into a given base
*/

# include <stdlib.h>

static int is_nbr_neg(int nbr)
{
    if (nbr < 0){
        my_putchar('-');
        return (1);
    }
    return (0);
}

static int get_nbr_base_length(int nbr, char const *base, int base_size)
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

static char *convert_nbr_to_str_base(int nbr, char const *base)
{
    int base_size = my_strlen(base);
    int quotient = nbr;
    int remainder = 0;
    int length = get_nbr_base_length(nbr, base, base_size);
    char *str = malloc(sizeof(char) * (length + 1));
    int i = 0;

    if (is_nbr_neg(nbr)) {
        nbr *= -1;
        quotient *= -1;
    }
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

char *convert_base(char const *nb, char const *base_from, char const *base_to)
{
    int decimal_nb = my_getnbr_base(nbr, base_from);
    char *str = convert_nbr_to_str_base(decimal_nb, base_to);

    return (str);
}