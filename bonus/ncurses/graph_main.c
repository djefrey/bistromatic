/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** graphical main file
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "evalexpr.h"
#include "bistromatic.h"
#include "operators.h"
#include "bonus_ncurses.h"

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

static void calculation(char **expr, calc_mode_t *calc_mode, history_t **hist)
{
    char *result;
    char *base = calc_mode->base;
    char *ops = calc_mode->ops;

    if (check_error(*expr, base, ops)) {
        replace_ans_save_expr(expr, "Syntax error", hist);
        return;
    }
    result = eval_expr(*expr, base, ops);
    if (result == NULL) {
        replace_ans_save_expr(expr, "Error", hist);
        return;
    }
    if (my_strlen(base) != 10 || my_strcmp(base, "0123456789") != 0)
        result = convert_dec_to_base(result, base);
    if (*result == '-')
        *result = SUB_OP(ops);
    replace_ans_save_expr(expr, result, hist);
}

static void free_history(history_t *history)
{
    history_t *tmp = history;
    history_t *cpy = tmp;

    while (tmp != NULL) {
        free(tmp->expr);
        free(tmp->result);
        tmp = tmp->prev;
        free(cpy);
        cpy = tmp;
    }
}

int main(int ac, char **av)
{
    WINDOW *expr_win;
    WINDOW *history_win;
    WINDOW *calc_mode_win;
    char *expr = malloc(sizeof(char) * 1);
    int c;
    int expr_len;
    int run = 1;
    history_t *history = NULL;
    calc_mode_t *calc_mode = malloc(sizeof(calc_mode_t));
    int offset = 0;

    expr[0] = 0;
    set_base(ac, av, calc_mode);
    set_ops(ac, av, calc_mode);
    init_window(&expr_win, &history_win, &calc_mode_win, calc_mode);
    while (run) {
        c = get_input();
        switch (c) {
            case ESC_KEY:
                run = 0;
                break;
            case ENTER_KEY:
                calculation(&expr, calc_mode, &history);
                print_expr(expr_win, expr, 0);
                print_history(history_win, history);
                offset = 0;
                break;
            case BACKSPACE_KEY:
                expr_len = my_strlen(expr);
                if (expr_len > 0)
                    expr[expr_len - 1] = 0;
                print_expr(expr_win, expr, offset);
                break;
            case LEFT_KEY:
                offset = offset > 0 ? offset - 1 : offset;
                print_expr(expr_win, expr, offset);
                break;
            case RIGHT_KEY:
                offset++;
                print_expr(expr_win, expr, offset);
                break;
            default:
                if (c != -1) {
                    expr = add_ch(expr, c);
                    print_expr(expr_win, expr, offset);
                }
                break;
        }
    }
    endwin();
    free_history(history);
    free(calc_mode->base);
    free(calc_mode->ops);
    free(calc_mode);
    free(expr);
    return (0);
}