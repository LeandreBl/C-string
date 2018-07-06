/*
** EPITECH PROJECT, 2018
** lblstr sources
** File description:
** short implémentation of C++ strings
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

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

int lstr_append(lstr_t *lstr, const char *str)
{
	size_t len = strlen(str);

	if (lstr_resize(lstr, lstr->len + len + 1) == -1)
		return (-1);
	strcpy(lstr->i + lstr->len, str);
	lstr->len += len;
	return (0);
}

int lstr_concat(lstr_t *lstr, const lstr_t *add)
{
	if (lstr_resize(lstr, lstr->len + add->len + 1) == -1)
		return (-1);
	strcpy(lstr->i + lstr->len, add->i);
	lstr->len += add->len;
	return (0);
}

void lstr_destroy(lstr_t *lstr)
{
	free(lstr->i);
}

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

int lstr_addch(lstr_t *lstr, char c)
{
	if (lstr_resize(lstr, lstr->len + 1) == -1)
		return (-1);
	lstr->i[lstr->len] = c;
	++lstr->len;
	return (0);
}

int lstr_create(lstr_t *lstr, const char *str)
{
	lstr->len = strlen(str);
	lstr->i = malloc(lstr->len + 1);
	if (lstr->i == NULL)
		return (-1);
	strcpy(lstr->i, str);
	lstr->rsize = lstr->len + 1;
	return (0);
}
