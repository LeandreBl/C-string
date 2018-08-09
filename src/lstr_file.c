/*
** EPITECH PROJECT, 2018
** lstr lib
** File description:
** lstr_file
*/

#include <unistd.h>
#include <fcntl.h>

#include "lstr.h"

ssize_t lstr_file(lstr_t *lstr, const char *pathname, ssize_t count)
{
	ssize_t rd;
	int fd = open(pathname, O_RDONLY);

	if (fd == -1)
		return (-1);
	rd = lstr_fd(lstr, fd, count);
	close(fd);
	return (rd);
}