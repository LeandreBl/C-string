/*
** EPITECH PROJECT, 2018
** lblstr
** File description:
** lblstr_tests
*/

#include <criterion/criterion.h>

#include "lblstr.h"

Test(lstr_create, various_tests)
{
	lstr_t str;

	cr_assert(lstr_create(&str, "test") == 0);
	cr_assert(str.len == 4);
	cr_assert(str.rsize > 4);
	cr_assert(strcmp(str.i, "test") == 0);
	lstr_destroy(&str);

	cr_assert(lstr_create(&str, "") == 0);
	cr_assert(str.len == 0);
	cr_assert(str.rsize > 0);
	cr_assert(strcmp(str.i, "") == 0);
	lstr_destroy(&str);

	cr_assert(lstr_create(&str, "testzerzlrkzlrkzlekrlkzelrkzlekrlzekrlklkaze") == 0);
	cr_assert(str.len == 44);
	cr_assert(str.rsize > 44);
	cr_assert(strcmp(str.i, "testzerzlrkzlrkzlekrlkzelrkzlekrlzekrlklkaze") == 0);
	lstr_destroy(&str);
}

Test(lstr_append, various_tests)
{
	lstr_t str;

	lstr_create(&str, "toto");
	cr_assert(lstr_append(&str, "salut") == 0);
	cr_assert(str.len == 9);
	cr_assert(str.rsize > 9);
	cr_assert(strcmp(str.i, "totosalut") == 0);
	lstr_destroy(&str);

	lstr_create(&str, "Jambon");
	cr_assert(lstr_append(&str, "") == 0);
	cr_assert(str.len == 6);
	cr_assert(str.rsize > 6);
	cr_assert(strcmp(str.i, "Jambon") == 0);
	lstr_destroy(&str);

	lstr_create(&str, "totosrltektjejterjtlerktlerktmelrkt");
	cr_assert(lstr_append(&str, "yoooooooooooooooolooooooooooooo") == 0);
	cr_assert(str.len == 66);
	cr_assert(str.rsize > 66);
	cr_assert(strcmp(str.i, "totosrltektjejterjtlerktlerktmelrktyoooooooooooooooolooooooooooooo") == 0);
	lstr_destroy(&str);
}

Test(lstr_concat, various_tests)
{
	lstr_t str;
	lstr_t add;

	lstr_create(&str, "toto");
	lstr_create(&add, "foo");
	cr_assert(lstr_concat(&str, &add) == 0);
	cr_assert(str.len == 7);
	cr_assert(str.rsize > 7);
	cr_assert(add.len == 3);
	cr_assert(add.rsize > 3);
	cr_assert(strcmp(str.i, "totofoo") == 0);
	cr_assert(strcmp(add.i, "foo") == 0);
	lstr_destroy(&str);
	lstr_destroy(&add);

	lstr_create(&str, "baobab");
	lstr_create(&add, "");
	cr_assert(lstr_concat(&str, &add) == 0);
	cr_assert(str.len == 6);
	cr_assert(str.rsize > 6);
	cr_assert(add.len == 0);
	cr_assert(add.rsize > 0);
	cr_assert(strcmp(str.i, "baobab") == 0);
	cr_assert(strcmp(add.i, "") == 0);
	lstr_destroy(&str);
	lstr_destroy(&add);
}

Test(lstr_set, various_tests)
{
	lstr_t str;

	lstr_create(&str, "bar");
	cr_assert(lstr_set(&str, "baobab") == 0);
	cr_assert(str.len == 6);
	cr_assert(str.rsize > 6);
	cr_assert(strcmp(str.i, "baobab") == 0);
	lstr_destroy(&str);

	lstr_create(&str, "foo");
	cr_assert(lstr_set(&str, "") == 0);
	cr_assert(str.len == 0);
	cr_assert(str.rsize > 0);
	cr_assert(strcmp(str.i, "") == 0);
	lstr_destroy(&str);

	lstr_create(&str, "useless");
	cr_assert(lstr_set(&str, "krtnnlmvbklkapzerozeptotjkjtkerjtkerjtkerjt") == 0);
	cr_assert(str.len == 43);
	cr_assert(str.rsize > 43);
	cr_assert(strcmp(str.i, "krtnnlmvbklkapzerozeptotjkjtkerjtkerjtkerjt") == 0);
	lstr_destroy(&str);
}

Test(lstr_format, various_tests)
{
	lstr_t str;

	lstr_create(&str, "cat");
	cr_assert(lstr_format(&str, "%c%s is a lion %d cm tall, I like %f trains",
		 ' ', "josephine", 30, 3.14) == 55);
	cr_assert(str.len == 55);
	cr_assert(str.rsize > 55);
	cr_assert(strcmp(str.i, " josephine is a lion 30 cm tall, I like 3.140000 trains") == 0);
	lstr_destroy(&str);
}

Test(lstr_resize, various_tests)
{
	lstr_t str;

	lstr_create(&str, "popol1233");
	cr_assert(lstr_resize(&str, 50) == 0);
	cr_assert(str.rsize > 50);
	cr_assert(strcmp(str.i, "popol1233") == 0);
	lstr_destroy(&str);

	lstr_create(&str, "foobar99");
	cr_assert(lstr_resize(&str, 3) == 0);
	cr_assert(str.rsize > 8);
	cr_assert(strcmp(str.i, "foo") == 0);
	lstr_destroy(&str);

	lstr_create(&str, "foobar99");
	cr_assert(lstr_resize(&str, 8) == 0);
	cr_assert(str.rsize > 8);
	cr_assert(strcmp(str.i, "foobar99") == 0);
	lstr_destroy(&str);
}

Test(lstr_addch, various_tests)
{
	lstr_t str;

	lstr_create(&str, "fooba");
	cr_assert(lstr_addch(&str, 'r') == 0);
	cr_assert(str.len == 6);
	cr_assert(str.rsize > 6);
	cr_assert(strcmp(str.i, "foobar") == 0);
	lstr_destroy(&str);

	lstr_create(&str, "");
	cr_assert(lstr_addch(&str, '-') == 0);
	cr_assert(str.len == 1);
	cr_assert(str.rsize > 1);
	cr_assert(strcmp(str.i, "-") == 0);
	lstr_destroy(&str);
}

Test(lstr_dup, various_tests)
{
	lstr_t str;
	lstr_t new;

	lstr_create(&str, "wololo");
	cr_assert(lstr_dup(&str, &new) == 0);
	cr_assert(new.len == 6);
	cr_assert(new.rsize > 6);
	cr_assert(strcmp(new.i, "wololo") == 0);
	lstr_destroy(&str);
	lstr_destroy(&new);

	lstr_create(&str, "");
	cr_assert(lstr_dup(&str, &new) == 0);
	cr_assert(new.len == 0);
	cr_assert(new.rsize > 0);
	cr_assert(strcmp(new.i, "") == 0);
	lstr_destroy(&str);
	lstr_destroy(&new);
}

Test(lstr_shift, various_tests)
{
	lstr_t str;

	lstr_create(&str, "1234567890");
	lstr_shift(&str, -1);
	cr_assert(str.len == 9);
	cr_assert(str.rsize > 9);
	cr_assert(strcmp(str.i, "234567890") == 0);

	lstr_shift(&str, 1);
	cr_assert(str.len == 8);
	cr_assert(str.rsize > 8);
	cr_assert(strcmp(str.i, "23456789") == 0);

	lstr_shift(&str, -5);
	cr_assert(str.len == 3);
	cr_assert(str.rsize > 3);
	cr_assert(strcmp(str.i, "789") == 0);

	lstr_shift(&str, 2);
	cr_assert(str.len == 1);
	cr_assert(str.rsize > 1);
	cr_assert(strcmp(str.i, "7") == 0);

	lstr_shift(&str, -11111);
	cr_assert(str.len == 0);
	cr_assert(str.rsize > 0);
	cr_assert(strcmp(str.i, "") == 0);

	lstr_set(&str, "toto");
	lstr_shift(&str, 100000);
	cr_assert(str.len == 0);
	cr_assert(str.rsize > 0);
	cr_assert(strcmp(str.i, "") == 0);
}

Test(lstr_remove, various_tests)
{
	lstr_t str;

	lstr_create(&str, "abcddefabcstddef.h");
	lstr_remove(&str, "abc");
	cr_assert(str.len == 12);
	cr_assert(str.rsize > 12);
	cr_assert(strcmp(str.i, "ddefstddef.h") == 0);

	lstr_remove(&str, "ddef");
	cr_assert(str.len == 4);
	cr_assert(str.rsize > 4);
	cr_assert(strcmp(str.i, "st.h") == 0);

	lstr_remove(&str, "toto");
	cr_assert(str.len == 4);
	cr_assert(str.rsize > 4);
	cr_assert(strcmp(str.i, "st.h") == 0);

	lstr_remove(&str, "");
	cr_assert(str.len == 4);
	cr_assert(str.rsize > 4);
	cr_assert(strcmp(str.i, "st.h") == 0);

	lstr_destroy(&str);
}

Test(lstr_replace, various_tests)
{
	lstr_t str;

	lstr_create(&str, "!CHAMPATATE RIEN MOK jambon");
	cr_assert(lstr_replace(&str, "PATATE", "PION") == 0);
	cr_assert(str.len == 25);
	cr_assert(str.rsize > 25);
	cr_assert(strcmp(str.i, "!CHAMPION RIEN MOK jambon") == 0);

	cr_assert(lstr_replace(&str, "RIEN", "DU") == 0);
	cr_assert(str.len == 23);
	cr_assert(str.rsize > 23);
	cr_assert(strcmp(str.i, "!CHAMPION DU MOK jambon") == 0);

	cr_assert(lstr_replace(&str, "MOK", "MONDE") == 0);
	cr_assert(str.len == 25);
	cr_assert(str.rsize > 25);
	cr_assert(strcmp(str.i, "!CHAMPION DU MONDE jambon") == 0);

	cr_assert(lstr_replace(&str, "!", "") == 0);
	cr_assert(str.len == 24);
	cr_assert(str.rsize > 24);
	cr_assert(strcmp(str.i, "CHAMPION DU MONDE jambon") == 0);

	cr_assert(lstr_replace(&str, "jambon", "!!!!!!!!!!!!!!") == 0);
	cr_assert(str.len == 32);
	cr_assert(str.rsize > 32);
	cr_assert(strcmp(str.i, "CHAMPION DU MONDE !!!!!!!!!!!!!!") == 0);
	lstr_destroy(&str);
}

Test(lstr_shrink_to_fit, various_tests)
{
	lstr_t str;

	lstr_create(&str, "Im barrely a rope");
	lstr_resize(&str, 5);
	cr_assert(lstr_shrink_to_fit(&str) == 0);
	cr_assert(str.len == 5);
	cr_assert(str.rsize == 6);
	cr_assert(strcmp(str.i, "Im ba") == 0);
	lstr_destroy(&str);
}