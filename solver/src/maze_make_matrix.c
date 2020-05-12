/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** maze_make_charmtx.c -- No description
*/

#include <errno.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <sys/cdefs.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "smart.h"
#include "solver.h"

static size_t count_lines(char const *maze1d)
{
    size_t n = 1;

    for (;;) {
        maze1d = strchr(maze1d, '\n');
        if (maze1d == NULL || *++maze1d == '\0')
            break;
        n += 1;
    }
    return n;
}

bool matrix_init(char const *const path, mtx_t *mtx)
{
    struct stat sb;
    autofp_t fp = fopen(path, "r");
    char wrongc;

    if (fp == NULL)
        return !!dprintf(2, "%s: %s\n", path, strerror(errno));
    stat(path, &sb);
    mtx->buff = malloc(sb.st_size / sizeof(*mtx->buff));
    if (mtx->buff == NULL)
        return !!dprintf(2, "%s: %s\n", __func__, strerror(errno));
    while (fread(mtx->buff, sizeof(*mtx->buff), sb.st_size, fp)) {}
    wrongc = mtx->buff[strspn(mtx->buff, "X*\n")];
    if (wrongc)
        return !!dprintf(2, "Forbidden character '%c' in %s\n", wrongc, path);
    return false;
}

bool maze_make_matrix(const char *const path)
{
    mtx_t *mtx = (mtx_t *) MTX;
    char *tmp = NULL;

    if (matrix_init(path, mtx))
        return true;
    mtx->y = count_lines(mtx->buff);
    mtx->x = strcspn(mtx->buff, "\n");
    tmp = mtx->buff;
    mtx->m = calloc(mtx->y, sizeof(*mtx->m));
    if (mtx->m == NULL)
        return !!dprintf(2, "Matrix allocation failed\n");
    for (int y = 0; y < mtx->y; y += 1)
        mtx->m[y] = strtok_r(tmp, "\n", &tmp);
    if (!is_path(0, 0) || !is_path(MTX->y - 1, MTX->x - 1))
        return !!dprintf(2, "Invalid entry or exit point.\n");
    return false;
}
