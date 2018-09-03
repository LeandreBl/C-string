/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lstr_dup
*/

#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "lstr.h"

int lstr_dup(const lstr_t *src, lstr_t *empty)
{
	empty->i = malloc(src->len + 1);
	empty->lock = malloc(sizeof(pthread_mutex_t));
	if (empty->i == NULL || empty->lock == NULL)
		return (-1);
	strcpy(empty->i, src->i);
	empty->len = src->len;
	empty->rsize = src->len + 1;
	*empty->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	return (0);
}
