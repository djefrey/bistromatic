/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** graphical main file
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "my.h"
#include "evalexpr.h"
#include "bistromatic.h"
#include "operators.h"
#include "bonus_ncurses.h"

static history_t *add_to_history(char *expr, char *result, history_t *prev)
{
    history_t *new = malloc(sizeof(history_t));

    new->expr = my_strdup(expr);
    new->result = my_strdup(result);
    new->prev = prev;
    return (new);
}

static void set_base(int ac, char **av, calc_mode_t *calc_mode)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'b') {
            calc_mode->base = &av[i][2];
            return;
        }
    }
    calc_mode->base = my_strdup("0123456789");
}

static void set_ops(int ac, char **av, calc_mode_t *calc_mode)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'o') {
            calc_mode->ops = &av[i][2];
            return;
        }
    }
    calc_mode->ops = my_strdup("()+-*/%");
}

static void calculation(char **expr, WINDOW *expr_win, calc_mode_t *calc_mode, history_t **hist)
{
    char *result = NULL;
    char *base = calc_mode->base;
    char *ops = calc_mode->ops;

    if (check_error(*expr, base, ops)) {
        print_expr(expr_win, "Syntax error");
        *hist = add_to_history(*expr, "Syntax error", *hist);
        return;
    }
    result = eval_expr(*expr, base, ops);
    if (result == NULL) {
        print_expr(expr_win, "Error");
        *hist = add_to_history(*expr, "Error", *hist);
        return;
    }
    if (my_strlen(base) != 10 || my_strcmp(base, "0123456789") != 0)
        result = convert_dec_to_base(result, base);
    if (*result == '-')
        *result = SUB_OP(ops);
    print_expr(expr_win, result);
    *hist = add_to_history(*expr, result, *hist);
}

int main(int ac, char **av)
{
    WINDOW *expr_win;
    WINDOW *history_win;
    char *expr = malloc(sizeof(char) * 1);
    int c;
    int expr_len;
    int run = 1;
    history_t *history = NULL;
    calc_mode_t *calc_mode = malloc(sizeof(calc_mode_t));

    expr[0] = 0;
    init_window(&expr_win, &history_win);
    set_base(ac, av, calc_mode);
    set_ops(ac, av, calc_mode);
    while (run) {
        c = getch();
        if (c >= 32 && c <= 126) {
            expr = add_ch(expr, c);
            print_expr(expr_win, expr);
            continue;
        }
        switch (c) {
            case 10:
                calculation(&expr, expr_win, calc_mode, &history);
                expr[0] = 0;
                print_history(history_win, history);
                break;
            case 127:
                expr_len = my_strlen(expr);
                if (expr_len > 0)
                    expr[expr_len - 1] = 0;
                print_expr(expr_win, expr);
                break;
            default:
                run = 0;
                break;
        }
    }
    endwin();
    return (0);
}