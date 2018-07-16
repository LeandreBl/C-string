/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_shrink_to_fit
*/

#include <stdlib.h>

#include "lblstr.h"

int lstr_shrink_to_fit(lstr_t *lstr)
{
	lstr->i = realloc(lstr->i, lstr->len + 1);
	if (lstr->i == NULL)
		return (-1);
	lstr->rsize = lstr->len + 1;
	return (0);
}