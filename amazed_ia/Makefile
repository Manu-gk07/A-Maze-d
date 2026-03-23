##
## EPITECH PROJECT, 2026
## A-Maze-d
## File description:
## Makefile
##

NAME		=	amazed

CC			=	clang

CFLAGS		=	-W -Wall -Wextra \
				-I./include \
				-I./lib/my_printf/include \
				-I./lib/other_functions

LDFLAGS		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio \
				-lcsfml-window -lm

LIBS		=	./lib/my_printf/my_printf.a \
				./lib/other_functions/other_functions.a

SRC			=	./src/main.c \
				./src/parser.c \
				./src/maze_generate.c \
				./src/algorithm.c \
				./src/display.c \
				./src/graphical_laberint.c

OBJ			=	$(SRC:.c=.o)

all:		libs $(NAME)

libs:
			@$(MAKE) --no-print-directory -C ./lib/my_printf
			@$(MAKE) --no-print-directory -C ./lib/other_functions

$(NAME):	$(OBJ)
			@$(CC) $(OBJ) $(LIBS) -o $(NAME) $(LDFLAGS)
			@printf "  LINK\t$(NAME)\n"

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(MAKE) --no-print-directory -C ./lib/my_printf clean
			@$(MAKE) --no-print-directory -C ./lib/other_functions clean
			@rm -f $(OBJ)

fclean:		clean
			@$(MAKE) --no-print-directory -C ./lib/my_printf fclean
			@$(MAKE) --no-print-directory -C ./lib/other_functions fclean
			@rm -f $(NAME)

re:			fclean all

debug:		CFLAGS += -g
debug:		re

.PHONY:		all libs clean fclean re debug
