/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** astar_neighbours.c -- No description
*/

#include <limits.h>
#include <stddef.h>

#include "solver.h"

static int get_y(direction_t dir, anode_t *parent)
{
    switch (dir) {
        case LEFT:
        case RIGHT: return parent->y;
        case DOWN: return parent->y + 1;
        case UP: return parent->y - 1;
        default: return -1;
    }
}

static int get_x(direction_t dir, anode_t *parent)
{
    switch (dir) {
        case DOWN:
        case UP: return parent->x;
        case LEFT: return parent->x - 1;
        case RIGHT: return parent->x + 1;
        default: return -1;
    }
}

static const char *DIRECTION[4] = {"UP", "DOWN", "LEFT", "RIGHT"};

void astar_search_neighbour(
    direction_t dir, bool clist[YMAX][XMAX], cell_t cell[YMAX][XMAX])
{
    cost_t cnew = ADATA->parent.c + 1;
    int y = get_y(dir, &ADATA->parent);
    int x = get_x(dir, &ADATA->parent);
    cell_t *nghbr = NULL;

    printf("   Going %-5s : [x %4i][y %4i] ─  ", DIRECTION[dir], x, y);

    if (!is_valid(y, x)) {

        printf("Ivalid position\n");

        return;
    }
    nghbr = &cell[y][x];
    if (is_dest(y, x)) {

        printf("Exit found !\n");

        nghbr->parent.y = ADATA->parent.y;
        nghbr->parent.x = ADATA->parent.x;
        ADATA->done = true;
    } else if (!clist[y][x] && is_path(y, x)
        && (nghbr->c == -1 || nghbr->c > cnew)) {
        astack_push(cnew, y, x);
        nghbr->c = cnew;
        nghbr->parent.y = ADATA->parent.y;
        nghbr->parent.x = ADATA->parent.x;

        printf("Cost = %li | Cell pushed to the opent list", cnew);
    } else {
        printf("Cost = %li | Cell skipped\n", cnew);
    }
}
