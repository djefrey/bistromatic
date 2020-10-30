/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** print fuctions
*/

#include <stdlib.h>
#include "bonus_ncurses.h"
#include "my.h"

void print_square(WINDOW *win, int origin[2], int size[2])
{
    int y = origin[0];
    int x = origin[1];
    int heigth = size[0] - 1;
    int width = size[1] - 1;

    mvwhline(win, y, x, 0, width);
    mvwhline(win, y + heigth, x, 0, width);
    mvwvline(win, y, x, 0, heigth);
    mvwvline(win, y, x + width, 0, heigth);
    mvwaddch(win, y, x, ACS_ULCORNER);
    mvwaddch(win, y + heigth, x, ACS_LLCORNER);
    mvwaddch(win, y + heigth, x + width, ACS_LRCORNER);
    mvwaddch(win, y, x + width, ACS_URCORNER);
}

void print_expr(WINDOW *expr_win, char *expr, int offset)
{
    int len = my_strlen(expr);
    int width = 3 * COLS / 4;
    char c;

    wclear(expr_win);
    box(expr_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(expr_win, 0, 3, " Calcul ");
    for (int i = 0; i < width - 6; i++) {
        c = i + offset < len ? expr[i + offset] : ' ';
        mvwaddch(expr_win, 2, i + 3, c);
    }
    mvwprintw(expr_win, 4, 3, " %i - %i ", offset, len);
    wrefresh(expr_win);
}

int move_cursor(int *line, int *col, int heigth, int width)
{
    *col += 1;
    if (*col == width - 3) {
        *col = 3;
        *line += 1;
    }
    if (*line == heigth - 2)
        return (0);
    return (1);
}

void print_history(WINDOW *history_win, history_t *history)
{
    int width = COLS / 3;
    int heigth = 3 * LINES / 4;
    int line = 2;
    int col = 3;

    wclear(history_win);
    box(history_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(history_win, 0, 3, " History ");
    while (line < heigth - 2 && history != NULL) {
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
        col = 3;
        history = history->prev;
    }
    wrefresh(history_win);
}