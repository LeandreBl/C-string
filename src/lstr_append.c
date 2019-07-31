/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_append
*/

#include <string.h>

#include "lstr.h"

int lstr_append(lstr_t *lstr, const char *str)
{
	size_t len = strlen(str);

	if (lstr_resize(lstr, lstr->len + len + 1) == -1)
		return (-1);
	memcpy(lstr->i + lstr->len, str, len + 1);
	(lstr->len) += len;
	return (0);
}
