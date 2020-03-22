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

void astar_search_neighbour(
    direction_t dir, bool clist[YMAX][XMAX], cell_t cell[YMAX][XMAX])
{
    unsigned long cnew = ADATA->parent.c + 1;
    int y = get_y(dir, &ADATA->parent);
    int x = get_x(dir, &ADATA->parent);
    cell_t *neighbour = NULL;

    if (!is_valid(y, x))
        return;
    neighbour = &cell[y][x];
    if (is_dest(y, x)) {
        neighbour->parent.y = ADATA->parent.y;
        neighbour->parent.x = ADATA->parent.x;
        ADATA->done = true;
    } else if (clist[y][x] && is_path(y, x) && neighbour->c > cnew) {
        astack_push(&ADATA->olist, cnew, y, x);
        neighbour->c = cnew;
        neighbour->parent.y = ADATA->parent.y;
        neighbour->parent.x = ADATA->parent.x;
    }
}
