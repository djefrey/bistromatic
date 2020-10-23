/*
** EPITECH PROJECT, 2020
** swap.c
** File description:
** swap the content of two int/strings pointers
*/

void my_intswap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}

void my_strswap(char **a, char **b)
{
    char *c = *a;

    *a = *b;
    *b = c;
}
