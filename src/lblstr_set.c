/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_set
*/

#include <string.h>
#include <stdlib.h>

#include "lblstr.h"

int lstr_set(lstr_t *lstr, const char *src)
{
	lstr->len = strlen(src);
	free(lstr->i);
	if (lstr_resize(lstr, lstr->len + 1) == -1)
		return (-1);
	strcpy(lstr->i, src);
	return (0);
}
