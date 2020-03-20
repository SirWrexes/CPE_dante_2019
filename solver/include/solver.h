/*
** EPITECH PROJECT, 2020
** Untitled project
** File description:
** solver.h -- No description
*/

#ifndef SOLVER_H
#define SOLVER_H

#include <stdbool.h>
#include <sys/cdefs.h>
#include <sys/types.h>

typedef struct {
    size_t x;
    size_t y;
    char **m;
} cmtx_t;

bool maze_to_matrix(char const *const path, cmtx_t *mtxp) __nonnull();

#endif /* !SOLVER_H */
