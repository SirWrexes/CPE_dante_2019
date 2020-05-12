/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** astar.h -- No description
*/

#ifndef ASTAR_H
#define ASTAR_H

#include <stdbool.h>

#include "cell.h"
#include "matrix.h"

typedef struct astar_node_s {
    int x;
    int y;
    cost_t c;
    struct anode_s *next;
} anode_t;

typedef struct astar_stack_s {
    anode_t *top;
} astack_t;

typedef struct astar_data_s {
    astack_t olist;
    anode_t parent;
    bool done;
} adata_t;

typedef enum { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 } direction_t;

extern const adata_t *ADATA_CONTAINER;
#define ADATA ((adata_t *) ADATA_CONTAINER)

bool astar_search(void);
void astar_search_neighbour(
    direction_t dir, bool clist[YMAX][XMAX], cell_t cell[YMAX][XMAX]);

#endif /* !ASTAR_H */
