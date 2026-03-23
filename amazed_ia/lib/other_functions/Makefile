##
## EPITECH PROJECT, 2026
## Module_name, project_name
## File description:
## Makefile - other_functions library
##

NAME	=	other_functions.a

CC		=	clang

CFLAGS	=	-W -Wall -Wextra -I./

SRC		=	my_array_len.c \
			my_atoi.c \
			my_evil_str.c \
			my_getnbr.c \
			my_isdigit.c \
			my_isneg.c \
			my_print_word_count.c \
			my_put_nbr.c \
			my_revstr.c \
			my_showmem.c \
			my_showstr.c \
			my_sort_int_array.c \
			my_strcapitalize.c \
			my_strcat.c \
			my_strchr.c \
			my_strcmp.c \
			my_str_contains.c \
			my_str_count_char.c \
			my_str_count_word.c \
			my_strcpy.c \
			my_strdup.c \
			my_str_isalnum.c \
			my_str_isalpha.c \
			my_str_islower.c \
			my_str_isnum.c \
			my_str_isupper.c \
			my_strjoin.c \
			my_strlen.c \
			my_strlowcase.c \
			my_strncat.c \
			my_strncmp.c \
			my_strncpy.c \
			my_strrchr.c \
			my_str_replace.c \
			my_strstr.c \
			my_strtrim.c \
			my_strupcase.c \
			my_swap.c \
			print_only_alpha.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@printf "  AR\t$(NAME)\n"

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
