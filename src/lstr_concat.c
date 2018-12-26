/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_concat
*/

#include <string.h>

#include "lstr.h"

int lstr_concat(lstr_t *lstr, const lstr_t *add)
{
  if (lstr_resize(lstr, lstr->len + add->len + 1) == -1)
    return (-1);
  memcpy(lstr->i + lstr->len, add->i, add->len + 1);
  (lstr->len) += add->len;
  return (0);
}
