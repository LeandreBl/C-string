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
	char buffer[4096];
	ssize_t rd = 0;
	size_t total = 0;
	size_t size = 0;

	if (null_tester(lstr, &size))
		return (-1);
	do {
		rd = read(fd, buffer, left_to_read(count, total, sizeof(buffer)));
		if (rd == -1)
			return (-1);
		size += rd;
		total += rd;
		if (lstr_resize(*lstr, size + 1) == -1)
			return (-1);
		memcpy((*lstr)->i + (*lstr)->len, buffer, rd);
		(*lstr)->len = size;
	} while (rd > 0);
	(*lstr)->i[(*lstr)->len] = 0;
	return ((*lstr)->len);
}