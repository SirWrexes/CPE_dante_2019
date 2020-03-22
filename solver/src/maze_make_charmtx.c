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

static bool make_matrix_step2(cmtx_t *cmtx)
{
    char *tmp = cmtx->buff;

    cmtx->c = calloc(cmtx->y, sizeof(*cmtx->c));
    for (int y = 0; y < cmtx->y; y += 1)
        cmtx->c[y] = strtok_r(tmp, "\n", &tmp);
    return false;
}

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

bool maze_make_charmtx(const char *const path, cmtx_t *cmtx)
{
    struct stat sb;
    autofp_t fp = fopen(path, "r");
    char wrongc;

    if (fp == NULL)
        return !!dprintf(2, "%s: %s\n", path, strerror(errno));
    stat(path, &sb);
    cmtx->buff = malloc(sb.st_size / sizeof(*cmtx->buff));
    if (cmtx->buff == NULL)
        return !!dprintf(2, "%s: %s\n", __func__, strerror(errno));
    while (fread(cmtx->buff, sizeof(*cmtx->buff), sb.st_size, fp)) {}
    wrongc = cmtx->buff[strspn(cmtx->buff, "X*\n")];
    if (wrongc)
        return !!dprintf(2, "Forbidden character '%c' in %s\n", wrongc, path);
    cmtx->y = count_lines(cmtx->buff);
    cmtx->x = strcspn(cmtx->buff, "\n");
    return make_matrix_step2(cmtx);
}
