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

static int null_tester(lstr_t **lstr, size_t *size)
{
	if (*lstr == NULL) {
		*lstr = malloc(sizeof(**lstr));
		if (*lstr == NULL)
			return (-1);
		memset(*lstr, 0, sizeof(**lstr));
	}
	else
		*size = (*lstr)->len;
	return (0);
}

ssize_t lstr_fd(lstr_t **lstr, int fd, ssize_t count)
{
	lstr_t *new;
	char buffer[4096];
	ssize_t rd = 0;
	size_t size = 0;

<<<<<<< HEAD
	new = calloc(1, sizeof(*new));
	if (new == NULL)
		return (NULL);
=======
	if (null_tester(lstr, &size))
		return (-1);
>>>>>>> Constructor functions now takes the address pointer of the pointer to fill with the string, lstr_format/fd/file now concat the wanted data, after the existing one if the address referenced pointer isn't NULL, if it's NULL, it creates it.
	do {
		rd = read(fd, buffer, left_to_read(count, size, sizeof(buffer)));
		if (rd == -1) {
			lstr_destroy(new);
			return (NULL);
		}
		size += rd;
<<<<<<< HEAD
		if (lstr_resize(new, size + 1) == -1) {
			lstr_destroy(new);
			return (NULL);
		}
		memcpy(new->i + new->len, buffer, rd);
		new->len = size;
	} while (rd > 0);
	new->i[new->len] = 0;
	return (new);
=======
		if (lstr_resize(*lstr, size + 1) == -1)
			return (-1);
		memcpy((*lstr)->i + (*lstr)->len, buffer, rd);
		(*lstr)->len = size;
	} while (rd > 0);
	(*lstr)->i[(*lstr)->len] = 0;
	return ((*lstr)->len);
>>>>>>> Constructor functions now takes the address pointer of the pointer to fill with the string, lstr_format/fd/file now concat the wanted data, after the existing one if the address referenced pointer isn't NULL, if it's NULL, it creates it.
}