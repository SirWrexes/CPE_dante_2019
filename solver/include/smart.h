/*
** EPITECH PROJECT, 2020
** Untitled project
** File description:
** smart.h -- No description
*/

#ifndef SMART_H
#define SMART_H


// Smart pointers
#include <malloc.h>

#define __getp(p) (* (void **) (p))

__nonnull() static inline void free_ptr(void *p)
{
    if (__getp(p) != NULL) {
        free(__getp(p));
        __getp(p) = NULL;
    }
}

#undef __getp

#define __smart __attribute__((cleanup(free_ptr)))

// Smart FILE streams
#include <stdio.h>

__nonnull() static inline void close_fp(FILE **fpp)
{
    if (*fpp != NULL) {
        fclose(*fpp);
        *fpp = NULL;
    }
}

#define autofp_t __attribute__((cleanup(close_fp))) FILE *

#endif /* !SMART_H */
