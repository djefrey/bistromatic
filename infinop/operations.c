/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** operations for infinadd
*/

#include <stdlib.h>
#include "my.h"
#include "operations.h"
#include "infinop.h"

char add_op(char c1, char c2, int *carry)
{
    int a = c1 - 48;
    int b = c2 - 48;
    int result = a + b + *carry;

    if (result > 9) {
        *carry = result / 10;
        result = result - 10;
    } else
        *carry = 0;
    return (result + 48);
}

char subs_op(char c1, char c2, int *carry)
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
    return (result + 48);
}

char mult_op(char c1, char c2, int *carry)
{
    int a = c1 - 48;
    int b = c2 - 48;
    int result = a * b + *carry;

    if (result > 9) {
        *carry = result / 10;
        result %= 10;
    } else
        *carry = 0;
    return (result + 48);
}

char div_op(char *c1, char *divisor)
{
    int n_times = 0;
    char *sub = infinsub(c1, divisor);
    char *mult;

    if (*sub == '-')
        return (48);
    while (*sub != '-') {
        n_times++;
        mult = infinmult(my_intstr(n_times + 1), divisor);
        sub = infinsub(c1, mult);
    }
    return (48 + n_times);
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