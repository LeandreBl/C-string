/*
** EPITECH PROJECT, 2018
** lblstr, string implémentation in C
** File description:
** header
*/

typedef struct lblstr_s lblstr;

#include <stddef.h>

struct lblstr_s {
	char *i;
	size_t len;
	size_t rsize;
	int (* append)(lblstr *self, const char *str);
	int (* concat)(lblstr *self, const lblstr *add);
	void (* destroy)(lblstr *self);
	int (* set)(lblstr *self, const char *src);
	int (* format)(lblstr *self, const char *format, ...);
	int (* resize)(lblstr *self, size_t new_size);
	int (* addch)(lblstr *self, char c);
};

int lblstr_create(lblstr *self, const char *str);
