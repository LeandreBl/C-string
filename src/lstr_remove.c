/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_remove
*/

#include <string.h>

#include "lstr.h"

void lstr_remove(lstr_t *lstr, const char *pattern)
{
    char *p;
    size_t size;

    size = strlen(pattern);
    if (size == 0 || size > lstr->len)
        return;
    p = strstr(lstr->i, pattern);
    while (p != NULL) {
        memmove(p, p + size, (lstr->i + lstr->len - p - size + 1));
        lstr->len -= size;
        p = strstr(p, pattern);
    }
}
