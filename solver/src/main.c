/*
** EPITECH PROJECT, 2019
** Untitled project
** File description:
** Main source
*/

#include <stdlib.h>
#include <stdio.h>

#include "solver.h"

int main(int ac, char **av)
{
    cmtx_t mtx = {0};

    (void) ac;
    if (maze_to_matrix(av[1], &mtx))
        return 84;
    for (size_t y = 0; y < mtx.y; y+= 1)
        printf("%s\n", mtx.m[y]);
    return EXIT_SUCCESS;
}
