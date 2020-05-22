/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** adata.h -- No description
*/

#ifndef ADATA_H
#define ADATA_H

#include <stdbool.h>

#include "astack.h"

typedef struct astar_data_s {
    astack_t stack;
    anode_t parent;
    bool done;
} adata_t;

extern const adata_t *ADATA_CONTAINER;
#define ADATA ((adata_t *) ADATA_CONTAINER)

#endif /* !ADATA_H */
