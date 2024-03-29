/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** astar_search.c -- No description
*/

#include <limits.h>
#include <stdbool.h>
#include <string.h>

#include "solver.h"

const adata_t *ADATA_CONTAINER = NULL;

static void draw_path(cell_t cell[YMAX][XMAX])
{
    int row = YMAX - 1;
    int col = XMAX - 1;

    while (row || col) {
        MTX->c[row][col] = 'o';
        row = cell[row][col].parent.y;
        col = cell[row][col].parent.x;
    }
}

static void astar_init(cell_t cell[YMAX][XMAX], bool clist[YMAX][XMAX])
{
    memset(clist, false, YMAX * XMAX * sizeof(**clist));
    for (int y = 0; y < YMAX; y += 1)
        for (int x = 0; x < XMAX; x += 1) {
            cell[y][x].parent.x = -1;
            cell[y][x].parent.y = -1;
            cell[y][x].c = ULONG_MAX;
        }
}

bool astar_search(void)
{
    bool clist[YMAX][XMAX];
    cell_t cell[YMAX][XMAX];
    adata_t data = {.olist = {0}, .parent = {0}, .done = false};

    astar_init(cell, clist);
    ADATA_CONTAINER = &data;
    astack_push(&data.olist, 0, 0, 0);
    while (data.olist.top != NULL) {
        astack_pop_into(&data.olist, &data.parent);
        clist[data.parent.y][data.parent.x] = true;
        for (direction_t dir = 0; dir < 4 && data.done == false; dir += 1)
            astar_search_neighbour(dir, clist, cell);
        if (data.done) {
            draw_path(cell);
            break;
        }
    }
    return data.done;
}
