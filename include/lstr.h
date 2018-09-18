/*
** EPITECH PROJECT, 2018
** lblstr, string implémentation in C
** File description:
** header
*/

#ifndef _LBLSTR_H
# define _LBLSTR_H

# include <stddef.h>
# include <sys/types.h>

typedef struct lblstr_s {
	char *i;
	pthread_mutex_t *lock;
	size_t len;
	size_t rsize;
} lstr_t;

lstr_t *lstr_create(const char *str);
void lstr_destroy(lstr_t *lstr);

int lstr_append(lstr_t *lstr, const char *str);
int lstr_concat(lstr_t *lstr, const lstr_t *add);
int lstr_set(lstr_t *lstr, const char *src);
lstr_t *lstr_format(const char *format, ...);
int lstr_resize(lstr_t *lstr, size_t new_size);
int lstr_addch(lstr_t *lstr, char c);
lstr_t *lstr_dup(const lstr_t *lstr);
void lstr_shift(lstr_t *lstr, int offset);
void lstr_remove(lstr_t *lstr, const char *pattern);
int lstr_replace(lstr_t *lstr, const char *replace, const char *by);
int lstr_shrink_to_fit(lstr_t *lstr);
int lstr_insert(lstr_t *lstr, size_t pos, const char *str);
void lstr_clear(lstr_t *lstr);
void lstr_erase(lstr_t *lstr, size_t pos, size_t len);
void lstr_swap(lstr_t *l1, lstr_t *l2);
lstr_t *lstr_fd(int fd, ssize_t count);
lstr_t *lstr_file(const char *pathname, ssize_t count);

int lstr_lock(lstr_t *lstr);
int lstr_unlock(lstr_t *lstr);

#endif /* !_LBLSTR_H */
