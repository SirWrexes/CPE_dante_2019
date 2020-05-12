/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** astack.h -- No description
*/

#ifndef ASTACK_H
#define ASTACK_H

#include <stdbool.h>

#include "cell.h"

typedef struct astar_node_s {
    int x;
    int y;
    cost_t c;
    struct anode_s *next;
} anode_t;

typedef struct astar_stack_s {
    anode_t *top;
} astack_t;

bool astack_push(cost_t c, int row, int col);
void astack_pop_into(anode_t *container);

#endif /* !ASTACK_H */
