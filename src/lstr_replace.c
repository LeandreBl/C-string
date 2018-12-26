/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_replace
*/

#include <string.h>

#include "lstr.h"

static size_t times_in(const char *in, const char *pattern)
{
  size_t n;
  const char *p = in;

  for (n = 0; p != NULL; ++n)
    p = strstr(p + 1, pattern);
  return (n);
}

static int need_resize(lstr_t *lstr, const char *replace, size_t len1,
                       size_t len2)
{
  size_t n;

  if (len1 < len2) {
    n = times_in(lstr->i, replace);
    if (lstr_resize(lstr, 1 + lstr->len + (len2 - len1) * n) == -1)
      return (-1);
    lstr->i[lstr->len + (len2 - len1) * n] = '\0';
  }
  return (0);
}

int lstr_replace(lstr_t *lstr, const char *replace, const char *by)
{
  char *p = lstr->i;
  size_t len1 = strlen(replace);
  size_t len2 = strlen(by);

  if (len2 == 0 || len1 == 0) {
    lstr_remove(lstr, replace);
    return (0);
  }
  if (need_resize(lstr, replace, len1, len2) == -1)
    return (-1);
  p = strstr(lstr->i, replace);
  while (p != NULL) {
    memmove(p + len2, p + len1, lstr->i + lstr->len - p - len1);
    memcpy(p, by, len2);
    lstr->len -= len1 - len2;
    lstr->i[lstr->len] = '\0';
    p = strstr(p + len2, replace);
  }
  return (0);
}
