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
	size_t len = strlen(src);

	if (lstr_resize(lstr, len + 1) == -1)
		return (-1);
	strcpy(lstr->i, src);
	lstr->len = len;
	return (0);
}
