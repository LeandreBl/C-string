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

int lstr_create(lstr_t *lstr, const char *str)
{
	lstr->len = strlen(str);
	lstr->i = malloc(lstr->len + 1);
	if (lstr->i == NULL)
		return (-1);
	strcpy(lstr->i, str);
	lstr->rsize = lstr->len + 1;
	lstr->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	return (0);
}

void lstr_destroy(lstr_t *lstr)
{
	free(lstr->i);
}
