/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** return 1 if str is only composed of digits
*/

unsigned char is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_digit(str[i]))
            return (0);
    }
    return (1);
}
