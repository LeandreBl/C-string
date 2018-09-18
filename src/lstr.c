/*
** EPITECH PROJECT, 2018
** lblstr sources
** File description:
** short implémentation of C++ strings
*/

#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "lstr.h"

lstr_t *lstr_create(const char *str)
{
	lstr_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->len = strlen(str);
	new->i = malloc(new->len + 1);
	new->lock = malloc(sizeof(pthread_mutex_t));
	if (new->i == NULL || new->lock == NULL) {
		lstr_destroy(new);
		return (NULL);
	}
	strcpy(new->i, str);
	new->rsize = new->len + 1;
	*new->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	return (new);
}

void lstr_destroy(lstr_t *lstr)
{
	free(lstr->i);
	free(lstr->lock);
	free(lstr);
}
