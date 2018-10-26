#include <pthread.h>

#include "lstr.h"

int lstr_lock(lstr_t *lstr)
{
	return (pthread_mutex_lock(&lstr->lock));
}

int lstr_unlock(lstr_t *lstr)
{
	return (pthread_mutex_unlock(&lstr->lock));
}