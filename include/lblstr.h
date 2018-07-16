/*
** EPITECH PROJECT, 2018
** lblstr, string implémentation in C
** File description:
** header
*/

#ifndef _LBLSTR_H
# define _LBLSTR_H

# include <stddef.h>

typedef struct lblstr_s {
	char *i;
	size_t len;
	size_t rsize;
} lstr_t;

int lstr_create(lstr_t *lstr, const char *str);
void lstr_destroy(lstr_t *lstr);

int lstr_append(lstr_t *lstr, const char *str);
int lstr_concat(lstr_t *lstr, const lstr_t *add);
int lstr_set(lstr_t *lstr, const char *src);
int lstr_format(lstr_t *lstr, const char *format, ...);
int lstr_resize(lstr_t *lstr, size_t new_size);
int lstr_addch(lstr_t *lstr, char c);
int lstr_dup(const lstr_t *lstr, lstr_t *dest);
void lstr_shift(lstr_t *lstr, int offset);
void lstr_remove(lstr_t *lstr, const char *pattern);
int lstr_replace(lstr_t *lstr, const char *replace, const char *by);
int lstr_shrink_to_fit(lstr_t *lstr);

#endif /* !_LBLSTR_H */