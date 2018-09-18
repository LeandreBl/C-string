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

lstr_t *lstr_dup(const lstr_t *src)
{
	lstr_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->i = malloc(src->len + 1);
	new->lock = malloc(sizeof(pthread_mutex_t));
	if (new->i == NULL || new->lock == NULL) {
		lstr_destroy(new);
		return (NULL);
	}
	strcpy(new->i, src->i);
	new->len = src->len;
	new->rsize = src->len + 1;
	*new->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	return (new);
}
