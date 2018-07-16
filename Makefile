##
## EPITECH PROJECT, 2017
##
## File description:
## makefile
##

NAME		= liblblstr.so

CC		= gcc

LIBS		=

SRCS		= src/lblstr.c
SRCS		+= src/lblstr_addch.c
SRCS		+= src/lblstr_append.c
SRCS		+= src/lblstr_concat.c
SRCS		+= src/lblstr_dup.c
SRCS		+= src/lblstr_format.c
SRCS		+= src/lblstr_remove.c
SRCS		+= src/lblstr_replace.c
SRCS		+= src/lblstr_resize.c
SRCS		+= src/lblstr_set.c
SRCS		+= src/lblstr_shift.c
SRCS		+= src/lblstr_shrink_to_fit.c
SRCS		+= src/lblstr_clear.c
SRCS		+= src/lblstr_insert.c
SRCS		+= src/lblstr_erase.c
SRCS		+= src/lblstr_swap.c

TESTS_SRCS := $(SRCS)
TESTS_SRCS += tests/lblstr_tests.c

OBJS		= $(SRCS:.c=.o)
TESTS_OBJS = $(TESTS_SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -Werror -Wall -Wextra -fPIC
CFLAGS		+= -I ./include
LDFLAGS		= -shared

GREEN		= '\033[0;32m'
NO_COLOR	= '\033[0m'

%.o : %.c
	@$ $(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CC) $(CFLAGS) -c $< -o $@ ["$(GREEN)"OK"$(NO_COLOR)"]"
.SUFFIXES: .o .c

all: $(NAME)

$(NAME): $(OBJS)
	@$ $(CC) $(LDFLAGS) $(OBJS) -o $@
	@echo "$(CC) $(LDFLAGS) $(OBJS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"

tests_run: $(TESTS_OBJS)
	@$ $(CC) -lcriterion $(TESTS_OBJS) -o $@
	@echo "$(CC) -lcriterion $(TESTS_OBJS) -o $@ \
	["$(GREEN)"LINKING OK"$(NO_COLOR)"]"
	./$@
	@$(RM) $@
	@$(RM) $(TESTS_OBJS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

install: re
	@cp $(NAME) /usr/lib/$(NAME) 2> /dev/null || \
	printf "\033[1m\033[31mError : try sudo make install\033[0m\n" && \
	cp include/lblstr.h /usr/include/lblstr.h 2> /dev/null && \
	printf "\033[1m\033[32mLibrary successfull installed !\033[0m\n"

.PHONY: all clean fclean re tests_run debug install
