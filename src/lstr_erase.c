/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lblstr_erase
*/

#include <string.h>

#include "lstr.h"

void lstr_erase(lstr_t *lstr, size_t pos, size_t len)
{
  if (pos > lstr->len)
    return;
  if (pos + len > lstr->len)
    len = lstr->len - pos;
  memmove(lstr->i + pos, lstr->i + pos + len, lstr->len - pos - len + 1);
  lstr->len -= len;
}