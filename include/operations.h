/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** header with operations
*/

#ifndef ADD_OPERATIONS_H
#define ADD_OPERATIONS_H

typedef char (*add_fct_t)(char n1, char n2, int* carry);
add_fct_t get_addop(char last1, char last2);

char add_op(char c1, char c2, int *carry);
char subs_op(char c1, char c2, int *carry);
char mult_op(char c1, char c2, int *carry);
char div_op(char *c1, char *divisor);

#endif