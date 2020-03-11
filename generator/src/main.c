/*
** EPITECH PROJECT, 2019
**
** File description:
** Main source
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

bool print_maze(int x, int y)
{
    int rd = 0;

    srand(time(NULL));

}

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;

    printf("*");
    for (int i = 0 ; i <= 10 ; i++) {
        rd = rand() % 2;
        printf("rand: %i\n", rd);
    }
    if (ac < 3 || ac > 4)
        return (84);
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x < 1 || y < 1)
        return (84);

    return (0);
}
