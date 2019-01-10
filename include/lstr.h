/*
** EPITECH PROJECT, 2018
** lblstr, string implémentation in C
** File description:
** header
*/

#ifndef _LBLSTR_H
# define _LBLSTR_H

# include <sys/types.h>
# include <sys/cdefs.h>

typedef struct lblstr_s {
	char *i;
	size_t len;
	size_t rsize;
} lstr_t;

int lstr_create(lstr_t *lstr_addr, const char *str) __THROW __nonnull((1));
ssize_t lstr_fd(lstr_t *lstr_addr, int fd, ssize_t count) __THROW __nonnull((1));
ssize_t lstr_file(lstr_t *lstr_addr, const char *pathname, ssize_t count) __THROW __nonnull((1, 2));
int lstr_format(lstr_t *lstr, const char *format, ...) __THROW __nonnull((1, 2)) __attribute__ ((__format__ (__printf__, 2, 0)));

void lstr_destroy(lstr_t *lstr) __THROW __nonnull((1));

int lstr_append(lstr_t *lstr, const char *str) __THROW __nonnull((1, 2));
int lstr_concat(lstr_t *lstr, const lstr_t *add) __THROW __nonnull((1, 2));
int lstr_set(lstr_t *lstr, const char *src, size_t len) __THROW __nonnull((1, 2));
int lstr_resize(lstr_t *lstr, size_t new_size) __THROW __nonnull((1));
int lstr_addch(lstr_t *lstr, char c) __THROW __nonnull((1));
int lstr_dup(lstr_t *dest, const lstr_t *lstr) __THROW __nonnull((1, 2));
void lstr_shift(lstr_t *lstr, int offset) __THROW __nonnull((1));
void lstr_remove(lstr_t *lstr, const char *pattern) __THROW __nonnull((1, 2));
int lstr_replace(lstr_t *lstr, const char *replace, const char *by) __THROW __nonnull((1, 2, 3));
int lstr_shrink_to_fit(lstr_t *lstr) __THROW __nonnull((1));
int lstr_insert(lstr_t *lstr, size_t pos, const char *str) __THROW __nonnull((1, 3));
void lstr_clear(lstr_t *lstr) __THROW __nonnull((1));
void lstr_erase(lstr_t *lstr, size_t pos, size_t len) __THROW __nonnull((1));
void lstr_swap(lstr_t *l1, lstr_t *l2) __THROW __nonnull((1, 2));

#endif /* !_LBLSTR_H */
