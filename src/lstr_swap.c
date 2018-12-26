/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lblstr_swap
*/

#include <string.h>

#include "lstr.h"

void lstr_swap(lstr_t *l1, lstr_t *l2)
{
  lstr_t temp;

  memcpy(&temp, l1, sizeof(temp));
  memcpy(l1, l2, sizeof(*l1));
  memcpy(l2, &temp, sizeof(*l2));
}