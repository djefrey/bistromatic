/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** bistromatic header
*/

#ifndef BISTROMATIC_H_
#define BISTROMATIC_H_

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

char check_error(char *expr, char *base, char *operators);
char *clean_expr(char *expr, char *base, char *operators);

#endif /* !BISTROMATIC_H_ */