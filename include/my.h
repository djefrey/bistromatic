/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header file of libmy
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);

unsigned char is_digit(char c);
int my_str_isnum(char const *str);

char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_getnbr(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
void my_fillstr(char *str, char c, int size);
char *my_intstr(int nb);
char *my_strcat(char *dest ,char const *src);
char *convert_base(char const *nb, char const *base_from, char const *base_to);

void my_intswap(int *a, int *b);
void my_strswap(char **a, char **b);

#endif
