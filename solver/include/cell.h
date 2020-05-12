/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** cell.h -- No description
*/

#ifndef CELL_H
#define CELL_H

#include <limits.h>

typedef long cost_t;
#define COST_MAX (LONG_MAX)

typedef struct {
    struct {
        int x;
        int y;
    } parent;
    cost_t c;
} cell_t;

#endif /* !CELL_H */
