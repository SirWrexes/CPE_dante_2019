/*
** EPITECH PROJECT, 2020
** Untitled project
** File description:
** solver.h -- No description
*/

#ifndef SOLVER_H
#define SOLVER_H

#include <stdbool.h>
#include <stdio.h>
#include <sys/cdefs.h>
#include <sys/types.h>

typedef unsigned long cost_t;

typedef enum { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 } direction_t;

typedef struct {
    struct {
        int x;
        int y;
    } parent;
    cost_t c;
} cell_t;

typedef struct {
    // Size
    int x;
    int y;

    // 2D matrix
    char **c;

    // Origin buffer pointer (to free at the end)
    char *buff;
} cmtx_t;

typedef struct anode_s {
    int x;
    int y;
    cost_t c;
    struct anode_s *next;
} anode_t;

typedef struct {
    anode_t *top;
} astack_t;

typedef struct astar_data_s {
    astack_t olist;
    anode_t parent;
    bool done;
} adata_t;

extern const adata_t *ADATA_CONTAINER;

#define ADATA ((adata_t *) ADATA_CONTAINER)

extern const cmtx_t *MTX;
#define XMAX (MTX->x)
#define YMAX (MTX->y)

bool astack_push(astack_t *stack, cost_t c, int row, int col);
void astack_pop_into(astack_t *stack, anode_t *container);

bool maze_make_charmtx(const char *const path, cmtx_t *cmtx);

static inline bool is_valid(int row, int col)
{
    return (row >= 0 && row < MTX->y) && (col >= 0 && col < MTX->x);
}

static inline bool is_path(int row, int col)
{
    return MTX->c[row][col] == '*';
}

static inline bool is_dest(int row, int col)
{
    return (row == MTX->x - 1) && (col == MTX->y - 1);
}

static inline void print_matrix()
{
    for (int y = 0; y < YMAX; y += 1)
        for (int x = 0; x < XMAX; x += 1)
            printf("%s\n", MTX->c[y]);
}

bool astar_search(void);
void astar_search_neighbour(
    direction_t dir, bool clist[YMAX][XMAX], cell_t cell[YMAX][XMAX]);

#endif /* !SOLVER_H */
