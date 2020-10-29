/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** ncurses header
*/

#ifndef BONUS_NCURSES_H_
#define BONUS_NCURSES_H_

#define DEFAULT_COLOR 1
#define HIGHLIGHT_COLOR 1

typedef struct history {
    char *expr;
    char *result;
    struct history *prev;
} history_t;

typedef struct calc_mode {
    char *base;
    char *ops;
} calc_mode_t;

int init_window(WINDOW **expr_win, WINDOW **history_win);
void print_expr(WINDOW *expr_win, char *expr);
void print_history(WINDOW *history_win, history_t *history);

char contains_char(char c, char *array);
char *add_ch(char *str, char c);

#endif /* !BONUS_NCURSES_H_ */