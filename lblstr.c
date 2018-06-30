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

int _resize(lblstr *self, size_t new_size)
{
	if (new_size != self->rsize) {
		if (new_size < self->rsize) {
			self->i[new_size++] = 0;
			self->len = strlen(self->i);
		}
		self->i = realloc(self->i, new_size);
		if (self->i == NULL)
			return (-1);
		self->rsize = new_size;
	}
	return (0);
}

int _append(lblstr *self, const char *str)
{
	size_t len = strlen(str);

	if (self->resize(self, self->len + len + 1) == -1)
		return (-1);
	strcpy(self->i + self->len, str);
	self->len += len;
	return (0);
}

int _concat(lblstr *self, const lblstr *add)
{
	if (self->resize(self, self->len + add->len + 1) == -1)
		return (-1);
	strcpy(self->i + self->len, add->i);
	self->len += add->len;
	return (0);
}

void _destroy(lblstr *self)
{
	free(self->i);
}

int _set(lblstr *self, const char *src)
{
	size_t len = strlen(src);

	free(self->i);
	self->i = malloc(len + 1);
	if (self->i == NULL)
		return (-1);
	strcpy(self->i, src);
	return (0);
}

int _format(lblstr *self, const char *format, ...)
{
	va_list va;
	int len;
	char *new;

	va_start(va, format);
	len = vasprintf(&new, format, va);
	if (len == -1)
		return (-1);
	free(self->i);
	self->i = new;
	self->len = (size_t)len;
	self->rsize = (size_t)len;
	va_end(va);
	return (len);
}

int _addch(lblstr *self, char c)
{
	if (self->resize(self, self->len + 1) == -1)
		return (-1);
	self->i[self->len] = c;
	++self->len;
	return (0);
}

int lblstr_create(lblstr *self, const char *str)
{
	self->len = strlen(str);
	self->i = malloc(self->len + 1);
	if (self->i == NULL)
		return (-1);
	strcpy(self->i, str);
	self->rsize = self->len + 1;
	self->append = _append;
	self->concat = _concat;
	self->destroy = _destroy;
	self->set = _set;
	self->format = _format;
	self->resize = _resize;
	self->addch = _addch;
	return (0);
}