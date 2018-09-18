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

lstr_t *lstr_format(const char *format, ...)
{
	lstr_t *str = malloc(sizeof(*str));
	int len;
	char *new;
	va_list va;

	if (str == NULL)
		return (NULL);
	va_start(va, format);
	len = vasprintf(&new, format, va);
	if (len == -1) {
		free(str);
		return (NULL);
	}
	str->i = new;
	str->len = (size_t)len;
	str->rsize = (size_t)len + 1;
	va_end(va);
	str->lock = malloc(sizeof(pthread_mutex_t));
	if (str->lock == NULL) {
		lstr_destroy(str);
		return (NULL);
	}
	return (str);
}
