/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** matrix.h -- No description
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    // Size
    int x;
    int y;

    // 2D matrix
    char **m;

    // Origin buffer pointer (to free at the end)
    char *buff;
} mtx_t;

extern const mtx_t *MTX;
#define XMAX (MTX->x)
#define YMAX (MTX->y)

static inline bool is_valid(int row, int col)
{
    return (row >= 0 && row < MTX->y) && (col >= 0 && col < MTX->x);
}

static inline bool is_path(int row, int col)
{
    return MTX->m[row][col] == '*';
}

static inline bool is_dest(int row, int col)
{
    return (row == YMAX - 1) && (col == XMAX - 1);
}

static inline void print_matrix()
{
    for (int y = 0; y < YMAX; y += 1)
        printf("%s\n", MTX->m[y]);
}

bool maze_make_matrix(const char *const path);

#endif /* !MATRIX_H */
