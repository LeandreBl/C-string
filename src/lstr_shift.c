/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_shift
*/

#include <string.h>

#include "lstr.h"

void lstr_shift(lstr_t *lstr, int offset)
{
    if ((offset < 0 && (size_t)-offset > lstr->len)
        || (offset > 0 && (size_t)offset > lstr->len)) {
        lstr->i[0] = '\0';
        lstr->len = 0;
    }
    else if (offset > 0) {
        lstr->len -= offset;
        lstr->i[lstr->len] = '\0';
    }
    else if (offset < 0) {
        lstr->len += offset;
        memmove(lstr->i, lstr->i - offset, lstr->len);
        lstr->i[lstr->len] = '\0';
    }
}
