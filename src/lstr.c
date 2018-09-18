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

int lstr_create(lstr_t **lstr, const char *str)
{
	*lstr = malloc(sizeof(**lstr));
	if (*lstr == NULL)
		return (-1);
	(*lstr)->len = strlen(str);
	(*lstr)->i = malloc((*lstr)->len + 1);
	(*lstr)->lock = malloc(sizeof(pthread_mutex_t));
	if ((*lstr)->i == NULL || (*lstr)->lock == NULL) {
		lstr_destroy(*lstr);
		return (-1);
	}
	strncpy((*lstr)->i, str, (*lstr)->len + 1);
	(*lstr)->rsize = (*lstr)->len + 1;
	*(*lstr)->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	return (0);
}

void lstr_destroy(lstr_t *lstr)
{
	free(lstr->i);
	free(lstr->lock);
	free(lstr);
}
