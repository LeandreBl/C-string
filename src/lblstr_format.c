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

#include "lblstr.h"

int lstr_format(lstr_t *lstr, const char *format, ...)
{
	va_list va;
	int len;
	char *new;

	va_start(va, format);
	len = vasprintf(&new, format, va);
	if (len == -1)
		return (-1);
	free(lstr->i);
	lstr->i = new;
	lstr->len = (size_t)len;
	lstr->rsize = (size_t)len;
	va_end(va);
	return (len);
}
