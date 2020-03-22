/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** astack_push.c -- No description
*/

#include <malloc.h>
#include <stdbool.h>
#include <string.h>

#include "solver.h"

void astack_pop_into(anode_t *container)
{
    anode_t *top = ADATA->olist.top;

    if (top != NULL)  {
        memcpy(container, ADATA->olist.top, sizeof(*container));
        container->next = NULL;
        ADATA->olist.top = top->next;
        free(top);
    }
}

bool astack_push(cost_t c, int row, int col)
{
    anode_t *node = malloc(sizeof(*node));

    if (node != NULL) {
        node->c = c;
        node->y = row;
        node->x = col;
        node->next = ADATA->olist.top;
        ADATA->olist.top = node;
    }
    return !(node != NULL);
}
