/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** inputs
*/

#include "bonus_ncurses.h"

static int get_arrow_key()
{
    getch();
    switch (getch()) {
        case 27:
            return (ESC_KEY);
        case 'A':
            return (UP_KEY);
        case 'B':
            return (DOWN_KEY);
        case 'C':
            return (RIGHT_KEY);
        case 'D':
            return (LEFT_KEY);
        default:
            return (UNDEFINED_KEY);
    }
}

int get_input(void)
{
    int c = getch();

    switch (c) {
        case '\033':
            return (get_arrow_key());
        case 10:
            return (ENTER_KEY);
        case 127:
            return (BACKSPACE_KEY);
    }
    if (c >= 32 && c <= 126)
        return (c);
    return (UNDEFINED_KEY);
}