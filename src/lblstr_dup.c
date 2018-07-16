/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_dup
*/

#include <string.h>
#include <stdlib.h>

#include "lblstr.h"

int lstr_dup(const lstr_t *src, lstr_t *empty)
{
	empty->i = malloc(src->len + 1);
	if (empty->i == NULL)
		return (-1);
	strcpy(empty->i, src->i);
	empty->len = src->len;
	empty->rsize = src->len + 1;
	return (0);
}
