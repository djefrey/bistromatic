/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** curses implementation
*/

#include <stdlib.h>
#include <math.h>
#include "bonus_ncurses.h"
#include "my.h"

static void init_expr_subwin(WINDOW **expr_win)
{
    int x = COLS / 8;
    int y = LINES / 12;
    int width = 3 * COLS / 4;
    int heigth = 5;

    *expr_win = subwin(stdscr, heigth, width, y, x);
    box(*expr_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(*expr_win, 0, 3, " Calcul ");
    mvwprintw(*expr_win, 4, 3, " 0 - 0 ");
}

static void init_hist_subwin(WINDOW **history_win)
{
    int x = 11 * COLS / 20;
    int y = LINES / 16 + 8;
    int width = COLS / 3;
    int heigth = 3 * LINES / 4;

    *history_win = subwin(stdscr, heigth, width, y, x);
    box(*history_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(*history_win, 0, 3, " History ");
}

static void init_base_box(WINDOW **calc_mode_win, calc_mode_t *calc_mode,
int win_width, int win_height)
{
    int base_len = my_strlen(calc_mode->base);
    int wsize;
    int hsize;
    int space = get_space_base_square(base_len, &wsize, &hsize);
    int width = 2 + 10 * wsize;
    int heigth = 2 + 5 * hsize;
    int base_oribox[2] = {(win_height - 7) / 2 - heigth / 2 + 7, win_width / 2 - width / 2};
    int base_sizebox[2] = {heigth, width};
    int line = 2;
    int col = 1 + space;

    print_square(*calc_mode_win, base_oribox, base_sizebox);
    mvwprintw(*calc_mode_win, base_oribox[0], base_oribox[1] + 3, " Base ");
    for (int i = 0; calc_mode->base[i]; i++) {
        mvwaddch(*calc_mode_win, base_oribox[0] + line, base_oribox[1] + col, calc_mode->base[i]);
        col += 2 * space;
        if (col >= (2 + 10 * wsize)) {
            col = 1 + space;
            line += space;
        }
    }
}

static void init_calc_mod_win(WINDOW **calc_mode_win, calc_mode_t *calc_mode)
{
    int x = 3 * COLS / 25;
    int y = LINES / 16 + 8;
    int width = COLS / 3;
    int heigth = 3 * LINES / 4;
    int ops_oribox[2] = {2, 3};
    int ops_sizebox[2] = {5, width - 6};

    *calc_mode_win = subwin(stdscr, heigth, width, y, x);
    box(*calc_mode_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(*calc_mode_win, 0, 3, " Mode ");
    print_square(*calc_mode_win, ops_oribox, ops_sizebox);
    mvwprintw(*calc_mode_win, ops_oribox[0], ops_oribox[1] + 3, " Operators ");
    for (int i = 0; i < 7; i++)
        mvwaddch(*calc_mode_win, 4, (i + 1) * width / 8, calc_mode->ops[i]);
    init_base_box(calc_mode_win, calc_mode, width, heigth);
}

int init_window(WINDOW **expr_win, WINDOW **history_win,
WINDOW **calc_mode_win, calc_mode_t *calc_mode)
{
    initscr();
    start_color();
    attron(A_BOLD);
    mvprintw(1, COLS / 2 - 6, "Bistromatic");
    attroff(A_BOLD);
    init_expr_subwin(expr_win);
    init_hist_subwin(history_win);
    init_calc_mod_win(calc_mode_win, calc_mode);
    refresh();
    noecho();
    curs_set(0);
    return (0);
}