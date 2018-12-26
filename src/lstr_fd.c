/*
** EPITECH PROJECT, 2018
** lbl str
** File description:
** lstr_fd
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "lstr.h"

static size_t left_to_read(ssize_t count, size_t size, size_t buffersize)
{
  if (count < 0)
    return (buffersize);
  if ((count - size) > buffersize)
    return (buffersize);
  return (count - size);
}

ssize_t lstr_fd(lstr_t *lstr, int fd, ssize_t count)
{
  char buffer[4096];
  ssize_t rd = 0;
  size_t total = 0;
  size_t size = 0;

  do {
    rd = read(fd, buffer, left_to_read(count, total, sizeof(buffer)));
    if (rd == -1)
      return (-1);
    size += rd;
    total += rd;
    if (lstr_resize(lstr, lstr->len + rd) == -1)
      return (-1);
    memcpy(lstr->i + lstr->len, buffer, rd);
    lstr->len = size;
  } while (rd > 0);
  lstr->i[lstr->len] = 0;
  return (lstr->len);
}