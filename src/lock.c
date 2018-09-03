#include <pthread.h>

#include "lstr.h"

int lstr_lock(lstr_t *str)
{
	return (pthread_mutex_lock(&str->lock));
}

int lstr_unlock(lstr_t *str)
{
	return (pthread_mutex_unlock(&str->lock));
}