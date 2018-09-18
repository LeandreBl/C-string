/*
** EPITECH PROJECT, 2018
** lstr lib
** File description:
** lstr_file
*/

#include <unistd.h>
#include <fcntl.h>

#include "lstr.h"

lstr_t *lstr_file(const char *pathname, ssize_t count)
{
	lstr_t *new;
	int fd = open(pathname, O_RDONLY);

	if (fd == -1)
		return (NULL);
	new = lstr_fd(fd, count);
	close(fd);
	return (new);
}