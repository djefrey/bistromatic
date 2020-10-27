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

char contains_char(char c, char *array);
char check_error(char *expr, char *base, char *operators);
char *convert_base_to_dec(char *nb, char *base);
char *convert_dec_to_base(char *nb, char *base);

#endif /* !BISTROMATIC_H_ */