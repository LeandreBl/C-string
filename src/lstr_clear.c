/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_clear
*/

#include "lstr.h"

void lstr_clear(lstr_t *lstr)
{
    lstr->i[0] = 0;
    lstr->len = 0;
}
