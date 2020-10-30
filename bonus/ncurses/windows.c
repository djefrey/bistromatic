/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** curses implementation
*/

#include <stdlib.h>
#include "bonus_ncurses.h"
#include "my.h"

void init_subwins(WINDOW **expr_win, WINDOW **history_win)
{
    *expr_win = subwin(stdscr, 5, 3 * COLS / 4, LINES / 16, COLS / 8);
    *history_win = subwin(stdscr, 3 * LINES / 4, COLS / 3, LINES / 16 + 8, 3 * COLS / 5);
    box(*expr_win, ACS_VLINE, ACS_HLINE);
    box(*history_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(*expr_win, 0, 3, " Calcul ");
    mvwprintw(*expr_win, 4, 3, " 0 - 0 ");
    mvwprintw(*history_win, 0, 3, " History ");
}

int init_window(WINDOW **expr_win, WINDOW **history_win)
{
    initscr();
    start_color();
    init_pair(DEFAULT_COLOR, COLOR_BLACK, COLOR_WHITE);
    init_pair(HIGHLIGHT_COLOR, COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(DEFAULT_COLOR));
    init_subwins(expr_win, history_win);
    refresh();
    noecho();
    curs_set(0);
    return (0);
}