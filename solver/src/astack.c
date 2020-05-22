/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** astack_push.c -- No description
*/

#include <malloc.h>
#include <stdbool.h>
#include <string.h>

#include "astack.h"
#include "adata.h"

void astack_pop_into(anode_t *container)
{
    anode_t *pop = astack_pop();

    if (pop != NULL) {
        memcpy(container, pop, sizeof(*pop));
        free(pop);
    }
}

anode_t *astack_pop(void)
{
    anode_t *pop = NULL;

    if (ADATA->stack.top != NULL)  {
        pop = ADATA->stack.top;
        ADATA->stack.top = ADATA->stack.top->next;
        pop->next = NULL;
    }
    return pop;
}

bool astack_push(cost_t cost, int row, int col)
{
    anode_t *node = malloc(sizeof(*node));

    if (node != NULL) {
        node->cost = cost;
        node->y = row;
        node->x = col;
        node->next = ADATA->stack.top;
        ADATA->stack.top = node;
    }
    return !(node != NULL);
}
