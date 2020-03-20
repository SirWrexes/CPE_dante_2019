/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** maze_to_matrix.c -- No description
*/

#include <errno.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <sys/cdefs.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <unistd.h>

#include "smart.h"
#include "solver.h"

__nonnull() static size_t count_lines(char const *buff)
{
    size_t n = 1;

    for (;;) {
        buff = strchr(buff, '\n');
        if (buff == NULL || *++buff == '\0')
            break;
        n += 1;
    }
    return n;
}

__nonnull() static bool make_matrix(char *buff, cmtx_t *mtxp)
{
    mtxp->y = count_lines(buff);
    mtxp->x = strcspn(buff, "\n");
    mtxp->m = calloc(mtxp->y, sizeof(*mtxp->m));
    if (mtxp->m == NULL)
        return !!dprintf(2, "[%s] %s\n", __func__, strerror(errno));
    for (size_t y = 0; y < mtxp->y; y += 1)
        mtxp->m[y] = strdup(strtok_r(buff, "\n", &buff));
    return false;
}

__nonnull() bool maze_to_matrix(char const *const path, cmtx_t *mtxp)
{
    struct stat sb;
    autofp_t fp = fopen(path, "r");
    __smart char *buff = NULL;
    char last;

    if (fp == NULL)
        return !!dprintf(2, "[%s] %s: %s\n", __func__, path, strerror(errno));
    stat(path, &sb);
    buff = calloc(sb.st_size / sizeof(*buff), sizeof(*buff));
    if (buff == NULL)
        return !!dprintf(2, "[%s] %s\n", __func__, strerror(errno));
    while (fread(buff, sizeof(char), sb.st_size, fp)) {}
    last = buff[strspn(buff, "X*\n")];
    if (last)
        return !!dprintf(
            2, "[%s] Forbidden character '%c' in %s\n", __func__, last, path);
    return make_matrix(buff, mtxp);
}
