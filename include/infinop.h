/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** infinop
*/

#ifndef INFINOP_H_
#define INFINOP_H_

typedef char *(*op_fct_t)(char *n1,char *n2);

op_fct_t get_infinop(char *op);

char *infinadd(char *n1, char *n2);
char *infinsub(char *nb1, char *nb2);
char *infinmult(char *n1, char *n2);
char *infindiv(char *nb1, char *nb2);
char *infinmod(char *nb1, char *nb2);

#endif