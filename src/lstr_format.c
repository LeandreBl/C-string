/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_format
*/

#define _GNU_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "lstr.h"

int lstr_format(lstr_t *lstr, const char *format, ...)
{
	va_list va;
	int len;
	char *new;

	va_start(va, format);
	len = vasprintf(&new, format, va);
	if (len == -1)
		return (-1);
	lstr->i = new;
	lstr->len = (size_t)len;
	lstr->rsize = (size_t)len + 1;
	va_end(va);
	return (len);
}
