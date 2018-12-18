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
    int fd = open(pathname, O_RDONLY);
    ssize_t size;

    if (fd == -1)
        return (-1);
    size = lstr_fd(lstr, fd, count);
    close(fd);
    return (size);
}