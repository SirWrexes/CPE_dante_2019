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

#include "adata.h"
#include "astack.h"
#include "cell.h"
#include "matrix.h"

#define print_matrix(x) maze_pretty_print()

bool astar_search(void);
void astar_search_neighbour(
    direction_t dir, bool clist[YMAX][XMAX], cell_t cell[YMAX][XMAX]);

void maze_pretty_print(void);

#endif /* !SOLVER_H */
