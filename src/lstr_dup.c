/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_dup
*/

#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "lstr.h"

int lstr_dup(lstr_t *dest, const lstr_t *src)
{
    dest->i = malloc(src->len + 1);
    if (dest->i == NULL) {
        lstr_destroy(dest);
        return (-1);
    }
    strncpy(dest->i, src->i, src->len + 1);
    dest->len = src->len;
    dest->rsize = src->len + 1;
    dest->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    return (0);
}
