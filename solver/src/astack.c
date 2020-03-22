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

void astack_pop_into(astack_t *stack, anode_t *container)
{
    anode_t *top = stack->top;

    if (top != NULL)  {
        memcpy(container, stack->top, sizeof(*container));
        container->next = NULL;
        stack->top = top->next;
        free(top);
    }
}

bool astack_push(astack_t *stack, cost_t c, int row, int col)
{
    anode_t *node = malloc(sizeof(*node));

    if (node != NULL) {
        node->c = c;
        node->y = row;
        node->x = col;
        node->next = stack->top;
        stack->top = node;
    }
    return !(node != NULL);
}
