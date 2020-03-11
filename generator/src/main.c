/*
** EPITECH PROJECT, 2019
**
** File description:
** Main source
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void print_line(int x)
{
    int rd = 0;

    for (int i = 0 ; i < x ; i++) {
        rd = rand() % 100;
        if (rd % 2)
            putchar('X');
        else
            putchar('*');
    }
}

bool print_maze(int x, int y)
{
    srand(time(NULL));
    putchar('*');
    print_line(x - 1);
    for (int i = 2 ; i < y ; i++) {
        putchar('\n');
        print_line(x);
    }
    putchar('\n');
    print_line(x - 1);
    putchar('*');
    return (false);
}

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;

    if (ac < 3 || ac > 4)
        return (84);
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x < 1 || y < 1)
        return (84);
    if (ac == 4 && strcmp("[perfect]", av[3]))
        return (84);
    if (print_maze(x, y))
        return (84);
    return (0);
}
