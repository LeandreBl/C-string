/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_resize
*/

#include <stdlib.h>
#include <string.h>

#include "lstr.h"

int lstr_resize(lstr_t *lstr, size_t new_size)
{
    if (new_size + 1 < lstr->rsize) {
        lstr->i[new_size] = 0;
        if (new_size < lstr->len)
            lstr->len = new_size;
    }
    else if (new_size + 1 > lstr->rsize) {
        lstr->i = realloc(lstr->i, new_size + 1);
        if (lstr->i == NULL)
            return (-1);
        lstr->rsize = new_size + 1;
    }
    return (0);
}
