/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** get_char_pos
*/

int get_char_pos(char *str, char goal)
{
    int i = 0;

    while (str && str[i] && str[i] != goal)
        ++i;
    if (!str || str[i] != goal)
        return (-1);
    return (i);
}