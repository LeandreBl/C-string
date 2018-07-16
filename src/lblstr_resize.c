/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_resize
*/

#include <stdlib.h>
#include <string.h>

#include "lblstr.h"

int lstr_resize(lstr_t *lstr, size_t new_size)
{
	if (new_size != lstr->rsize) {
		if (new_size < lstr->rsize) {
			lstr->i[new_size++] = 0;
			lstr->len = strlen(lstr->i);
		}
		lstr->i = realloc(lstr->i, new_size);
		if (lstr->i == NULL)
			return (-1);
		lstr->rsize = new_size;
	}
	return (0);
}
