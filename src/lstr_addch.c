/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_addch
*/

#include "lstr.h"

int lstr_addch(lstr_t *lstr, char c)
{
	if (lstr_resize(lstr, lstr->len + 1) == -1)
		return (-1);
	lstr->i[lstr->len] = c;
	++lstr->len;
	return (0);
}
