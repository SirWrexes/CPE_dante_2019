/*
** EPITECH PROJECT, 2020
** Dante's Star (solver)
** File description:
** maze_pretty_print.c -- No description
*/

#include <stdio.h>

#include "solver.h"

static char const *get_color(int row, int col)
{
    switch (MTX->m[row][col]) {
        default: return NULL;
        case '*': return "\033[47m";
        case 'X': return "\033[41m";
        case 'o': return "\033[42m";
        case '?': return "\033[100m";
    }
}

void maze_pretty_print(void)
{
    int padx, pady;
    int xmax = XMAX, ymax = YMAX;

    for (padx = 0; xmax; xmax /= 10, padx += 1) {}
    for (pady = 0; ymax; ymax /= 10, pady += 1) {}
    padx += 1;
    for (int x = 0; x < pady + padx - 2; x += 1)
        printf(" ");
    printf("\033[4m");
    for (int x = 0; x < XMAX; x += 1)
        printf(" %-*i", padx - 1, x);
    printf("\033[0m\n");
    for (int y = 0; y < YMAX; y += 1) {
        printf("%*i|", pady, y);
        for (int x = 0; x < XMAX; x += 1)
            printf("%s%*c\033[0m", get_color(y, x), padx, ' ');
        printf("\n");
    }
}
