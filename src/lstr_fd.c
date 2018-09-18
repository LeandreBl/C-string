/*
** EPITECH PROJECT, 2018
** lbl str
** File description:
** lstr_fd
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "lstr.h"

static size_t left_to_read(ssize_t count, size_t size, size_t buffersize)
{
	if (count < 0)
		return (buffersize);
	if ((count - size) > buffersize)
		return (buffersize);
	return (count - size);
}

lstr_t *lstr_fd(int fd, ssize_t count)
{
	lstr_t *new;
	char buffer[4096];
	ssize_t rd;
	size_t size = 0;

	new = calloc(1, sizeof(*new));
	if (new == NULL)
		return (NULL);
	do {
		rd = read(fd, buffer, left_to_read(count, size, sizeof(buffer)));
		if (rd == -1) {
			lstr_destroy(new);
			return (NULL);
		}
		size += rd;
		if (lstr_resize(new, size + 1) == -1) {
			lstr_destroy(new);
			return (NULL);
		}
		memcpy(new->i + new->len, buffer, rd);
		new->len = size;
	} while (rd > 0);
	new->i[new->len] = 0;
	return (new);
}