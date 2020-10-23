/*
** EPITECH PROJECT, 2020
** my_fillstr
** File description:
** fill a string with a define char
*/

void my_fillstr(char *str, char c, int size)
{
    for (int i = 0; i < size; i++)
        *(str + i) = c;
    *(str + size) = '\0';
}