/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** evalexpr header
*/

#ifndef EVALEXPR_H_
#define EVALEXPR_H_

char *number(char **str_ptr, char *base, char *operators);
char *brackets(char **str_ptr, char *base, char *operators);
char *factors(char **str_ptr, char *base, char *operators);
char *summands(char **str_ptr, char *base, char *operators);
char *eval_expr(char const *str, char *base, char *operators);

#endif /* !EVALEXPR_H_ */