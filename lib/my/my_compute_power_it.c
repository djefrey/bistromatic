/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** return the given number to the power given
*/

int my_compute_power_it(int nb, int p)
{
    long result = 1;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    for (int i = 0; i < p; i++) {
        result *= nb;
        if (!is_valid_int(result))
            return (0);
    }
    return result;
}