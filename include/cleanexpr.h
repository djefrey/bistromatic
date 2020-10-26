/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** cleanexpr header
*/

#ifndef CLEAN_EXPR_H_
#define CLEAN_EXPR_H_

#define OPEN_BRACKET(operators) (operators[0])
#define CLOSE_BRACKET(operators) (operators[1])
#define ADD_OP(operators) (operators[2])
#define SUB_OP(operators) (operators[3])
#define MULT_OP(operators) (operators[4]])
#define DIV_OP(operators) (operators[5])
#define MOD_OP(operators) (operators[6])

char *clean_expr(char *expr, char *base, char *operators);

#endif /* !CLEAN_EXPR_H_ */