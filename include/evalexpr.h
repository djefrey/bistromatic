/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** evalexpr header
*/

#ifndef EVALEXPR_H_
#define EVALEXPR_H_

char *number(char **str_ptr);
char *brackets(char **str_ptr);
char *factors(char **str_ptr);
char *summands(char **str_ptr);
char *eval_expr(char const *str);

#endif /* !EVALEXPR_H_ */