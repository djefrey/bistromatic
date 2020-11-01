/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** ncurses header
*/

#ifndef BONUS_NCURSES_H_
#define BONUS_NCURSES_H_

#include <ncurses.h>

#define UNDEFINED_KEY -1
#define ESC_KEY 0
#define BACKSPACE_KEY 1
#define ENTER_KEY 2
#define LEFT_KEY 3
#define RIGHT_KEY 4
#define UP_KEY 5
#define DOWN_KEY 6

typedef struct history {
    char *expr;
    char *result;
    struct history *prev;
} history_t;

typedef struct calc_mode {
    char *base;
    char *ops;
} calc_mode_t;

int init_window(WINDOW **expr_win, WINDOW **history_win,
WINDOW **calc_mode_win, calc_mode_t *calc_mode);

void print_square(WINDOW *win, int origin[2], int size[2]);
void print_expr(WINDOW *expr_win, char *expr, int offset);
void print_history(WINDOW *history_win, history_t *history, int offset);

int get_input(void);

void replace_and_save_expr(char **expr, char *result, history_t **hist);
char contains_char(char c, char *array);
char *add_ch(char *str, char c);
int get_space_base_square(int base_len, int *width, int *heigth);

#endif /* !BONUS_NCURSES_H_ */