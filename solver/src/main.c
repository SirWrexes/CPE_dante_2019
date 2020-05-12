/*
** EPITECH PROJECT, 2019
** Untitled project
** File description:
** Main source
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smart.h"
#include "solver.h"

const mtx_t *MTX = NULL;

int main(int ac, char **av)
{
    mtx_t cmtx = {0};

    if (ac != 2)
        return 84 | !dprintf(2, "Wrong argument count: %d\n", ac);
    MTX = &cmtx;
    if (maze_make_matrix(av[1]))
        return 84;
    printf("Maze matrix (unaltered):\n");
    print_matrix();
    printf("\n\n");
    if (astar_search()) {
        print_matrix();
        return EXIT_SUCCESS;
    } else
        return 84 | !dprintf(2, "Maze is not solvable.\n");
}
