/*
** EPITECH PROJECT, 2019
** Dante generator
** File description:
** Main source
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void free_maze(char **mz)
{
    int i;

    for (i = 0 ; mz[i + 1] ; i++) {
        printf("%s\n", mz[i]);
    }
    printf("%s", mz[i]);
    for (i = 0 ; mz[i] ; i++) {
        free(mz[i]);
    }
    free(mz);
}

char **create_maze(int x, int y)
{
    char **mz = NULL;

    mz = malloc((x + 1) * sizeof(char *));
    if (mz == NULL)
        return (NULL);
    mz[x] = NULL;
    for (int i = 0 ; i < x ; i++) {
        mz[i] = malloc(y * sizeof(char) + 1);
        if (mz[i] == NULL)
            return (NULL);
        mz[i][y] = '\0';
        for (int j = 0 ; j < y ; j++)
            mz[i][j] = '*';
    }
    return (mz);
}

char **generate_maze(char **mz, int x, int y)
{
    int rdx = 0;
    int rdy = 0;

    srandom(time(NULL));
    while (rdy < 1)
        rdy = random() % y;
    rdx = random() % x;
    for (int i = 0 ; mz[i] ; i++) {
        if (i != rdx)
            mz[i][rdy] = 'X';
    }
    return (mz);
}

int main(int ac, char **av)
{
    char **mz = NULL;
    int x = 0;
    int y = 0;

    if (ac < 3 || ac > 4) {
        return (84);
    } else if (ac == 4 && strcmp("[perfect]", av[3])) {
        return (84);
    } else {
        x = atoi(av[2]);
        y = atoi(av[1]);
    }
    if (x <= 1 || y <= 1)
        return (84);
    mz = create_maze(x, y);
    if (mz == NULL)
        return (84);
    mz = generate_maze(mz, x - 1, y - 1);
    free_maze(mz);
    return (0);
}
