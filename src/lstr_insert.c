/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lblstr_insert
*/

#include <string.h>
#include <stdlib.h>

#include "lstr.h"

int need_resize(lstr_t *lstr, size_t pos, const char *str, size_t len)
{
	char *new;

	new = malloc(lstr->len + len + 1);
	if (new == NULL)
		return (-1);
	strncpy(new, lstr->i, pos);
	strncpy(new + pos, str, len);
	strcpy(new + pos + len, lstr->i + pos);
	free(lstr->i);
	lstr->i = new;
	lstr->rsize = lstr->len + len + 1;
	lstr->len += len;
	return (0);
}

int lstr_insert(lstr_t *lstr, size_t pos, const char *str)
{
	size_t len = strlen(str);

	if (pos > lstr->len || len == 0)
		return (-1);
	if (lstr->len + len + 1 > lstr->rsize)
		return (need_resize(lstr, pos, str, len));
	else {
		memmove(lstr->i + pos + len, lstr->i + pos, lstr->len - pos + 1);
		strncpy(lstr->i + pos, str, len);
		lstr->len += len;
	}
	return (0);
}