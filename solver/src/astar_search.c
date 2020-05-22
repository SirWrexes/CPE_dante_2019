/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** astar_search.c-- No description
*/

#include <limits.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

#include "solver.h"

const adata_t *ADATA_CONTAINER = NULL;

static void draw_path(cell_t cell[YMAX][XMAX])
{
    int row = YMAX - 1;
    int col = XMAX - 1;

    print_matrix();
    printf("Current ─ Row: %3d, Col: %3d\n", row, col);
    printf("Parent  ─ Row: %3d, Col: %3d\n", cell[row][col].parent.y,
        cell[row][col].parent.x);
    MTX->m[row][col] = 'o';
    while (row || col) {
        print_matrix();
        printf("Current ─ Row: %3d, Col: %3d\n", row, col);
        printf("Parent  ─ Row: %3d, Col: %3d\n", cell[row][col].parent.y,
            cell[row][col].parent.x);
        row = cell[row][col].parent.y;
        col = cell[row][col].parent.x;
        MTX->m[row][col] = 'o';
    }
}

static void astar_init(cell_t cell[YMAX][XMAX], bool clist[YMAX][XMAX])
{
    memset(clist, false, YMAX * XMAX * sizeof(**clist));
    for (int y = 0; y < YMAX; y += 1)
        for (int x = 0; x < XMAX; x += 1) {
            cell[y][x].parent.x = -1;
            cell[y][x].parent.y = -1;
            cell[y][x].cost = COST_MAX;
        }
}

bool astar_search(void)
{
    bool visited[YMAX][XMAX];
    cell_t cell[YMAX][XMAX];
    adata_t data = {.stack = {0}, .parent = {0}, .done = false};

    astar_init(cell, visited);
    ADATA_CONTAINER = &data;
    astack_push(0, 0, 0);
    while (data.stack.top != NULL) {
        astack_pop_into(&data.parent);
        visited[data.parent.y][data.parent.x] = true;
        for (direction_t dir = 0; dir < 4 && data.done == false; dir += 1)
            astar_search_neighbour(dir, visited, cell);
        if (data.done) {
            draw_path(cell);
            break;
        }
    }
    return data.done;
}
