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

const cmtx_t *MTX = NULL;

// #define astar_search() 0

int main(int ac, char **av)
{
    cmtx_t cmtx = {0};

    if (ac != 2)
        return 84 | !dprintf(2, "Wrong argument count: %d\n", ac);
    MTX = &cmtx;
    if (maze_make_charmtx(av[1], &cmtx))
        return 84;
    if (!is_path(0, 0) || !is_path(cmtx.y - 1, cmtx.x - 1))
        return 84 | !dprintf(2, "Invalid entry or exit point.\n");
    printf("Maze matrix (unaltered):\n");
    maze_pretty_print();
    printf("\n\n");
    if (astar_search()) {
        maze_pretty_print();
        return EXIT_SUCCESS;
    } else
        return 84 | !dprintf(2, "Maze is not solvable.\n");
}
