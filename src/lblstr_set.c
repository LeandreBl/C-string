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

	free(lstr->i);
	lstr->i = malloc(len + 1);
	if (lstr->i == NULL)
		return (-1);
	strcpy(lstr->i, src);
	return (0);
}
