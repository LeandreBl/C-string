/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_format
*/

#define _GNU_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lstr.h"

int lstr_format(lstr_t *lstr, const char *format, ...)
{
  va_list va;
  va_list dup;
  int len;

  va_start(va, format);
  va_copy(dup, va);
  len = vsnprintf(NULL, 0, format, dup);
  if (len == -1)
    return (-1);
  lstr_resize(lstr, lstr->rsize + len + 1);
  len = vsnprintf(lstr->i + lstr->len, lstr->rsize - 1, format, va);
  lstr->len += len;
  va_end(va);
  return (len);
}
