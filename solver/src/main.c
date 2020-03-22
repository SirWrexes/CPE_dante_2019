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

static void draw_path(void)
{
    int row = YMAX - 1;
    int col = XMAX - 1;

    while (row || col) {
        MTX->c[row][col] = 'o';
        row = ADATA->cell[row][col].parent.y;
        col = ADATA->cell[row][col].parent.x;
    }
}

int main(int ac, char **av)
{
    cmtx_t cmtx = {0};

    (void) ac;
    MTX = &cmtx;
    if (maze_make_charmtx(av[1], &cmtx))
        return 84;
    if (!is_path(0, 0) || !is_path(cmtx.y - 1, cmtx.x - 1))
        return 84 | !dprintf(2, "Invalid entry or exit point.\n");
    if (astar_search()) {
        draw_path();
        print_matrix();
        return EXIT_SUCCESS;
    } else
        return 84 | !dprintf(2, "Maze is not solvable.\n");
}
