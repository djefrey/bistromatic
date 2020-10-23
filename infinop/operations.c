/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** operations for infinadd
*/

#include <stdlib.h>
#include "my.h"
#include "operations.h"

int add_op(char c1, char c2, int *carry)
{
    int a = c1 - 48;
    int b = c2 - 48;
    int result = a + b + *carry;

    if (result > 9) {
        *carry = result / 10;
        result = result - 10;
    } else
        *carry = 0;
    return (result);
}

int subs_op(char c1, char c2, int *carry)
{
    int a = c1 - 48;
    int b = c2 - 48;
    int result = a - b + *carry;

    if (result < 0) {
        *carry = (result - 9) / 10;
        result = 10 + result;
    } else {
        *carry = 0;
    }
    return (result);
}

int mult_op(char c1, char c2, int *carry)
{
    int a = c1 - 48;
    int b = c2 - 48;
    int result = a * b + *carry;

    if (result > 9) {
        *carry = result / 10;
        result %= 10;
    } else
        *carry = 0;
    return (result);
}

char *div_op(char *c1, char *divisor)
{
    char *n_str = my_intstr(0);
    char *sub = infinsub(c1, divisor);
    char *mult;
    int n_times = 0;

    while (*sub != '-') {
        n_times++;
        n_str = my_intstr(n_times);
        mult = infinmult(n_str, divisor);
        sub = infinsub(c1, mult);
        if (!(*sub == '0' && *(sub + 1) == '\0'))
            break;
    }
    if (n_times > 1 && *sub == '-')
        n_str = my_intstr(n_times - 1);
    return (n_str);
}

add_fct_t get_addop(char last1, char last2)
{
    if (last1 == '-' && last2 == '-')
        return (&add_op);
    else if (last1 == '-' || last2 == '-')
        return (&subs_op);
    else
        return (&add_op);
}