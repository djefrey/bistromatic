/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** curses implementation
*/

#include <stdlib.h>
#include <ncurses.h>
#include "bonus_ncurses.h"
#include "my.h"

int move_cursor(int *line, int *col, int heigth, int width)
{
    *col += 1;
    if (*col == width - 1) {
        *col = 1;
        *line += 1;
    }
    if (*line == heigth - 1)
        return (0);
    return (1);
}

void print_expr(WINDOW *expr_win, char *expr)
{
    wclear(expr_win);
    box(expr_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(expr_win, 0, 3, " Calcul ");
    mvwprintw(expr_win, 2, 3, expr);
    wrefresh(expr_win);
}

void print_history(WINDOW *history_win, history_t *history)
{
    int width = COLS / 3;
    int heigth = 3 * LINES / 4;
    int line = 1;
    int col = 1;

    wclear(history_win);
    box(history_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(history_win, 0, 3, " History ");
    while (line < heigth - 1 && history != NULL) {
        for (int i = 0; history->expr[i]; i++) {
            mvwaddch(history_win ,line, col, history->expr[i]);
            if (!move_cursor(&line, &col, heigth, width))
                return;
        }
        for (int i = 0; i < 3; i++) {
            mvwaddch(history_win ,line, col, " = "[i]);
            if (!move_cursor(&line, &col, heigth, width))
                return;
        }
        for (int i = 0; history->result[i]; i++) {
            mvwaddch(history_win ,line, col, history->result[i]);
            if (!move_cursor(&line, &col, heigth, width))
                return;
        }
        line++;
        col = 1;
        history = history->prev;
    }
    wrefresh(history_win);
}

int init_window(WINDOW **expr_win, WINDOW **history_win)
{
    initscr();
    start_color();
    init_pair(DEFAULT_COLOR, COLOR_BLACK, COLOR_WHITE);
    init_pair(HIGHLIGHT_COLOR, COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(DEFAULT_COLOR));
    *expr_win = subwin(stdscr, 5, 3 * COLS / 4, LINES / 16, COLS / 8);
    *history_win = subwin(stdscr, 3 * LINES / 4, COLS / 3, LINES / 16 + 8, 3 * COLS / 5);
    box(*expr_win, ACS_VLINE, ACS_HLINE);
    box(*history_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(*expr_win, 0, 3, " Calcul ");
    mvwprintw(*history_win, 0, 3, " History ");
    refresh();
    noecho();
    curs_set(0);
    return (0);
}