##
## EPITECH PROJECT, 2026
## Module_name, project_name
## File description:
## Makefile - my_printf library
##

NAME	=	my_printf.a

CC		=	clang

CFLAGS	=	-W -Wall -Wextra -I./include

SRC		=	src/my_0.c \
			src/my_c.c \
			src/my_d.c \
			src/my_e.c \
			src/my_ee.c \
			src/my_f.c \
			src/my_g.c \
			src/my_o.c \
			src/my_p.c \
			src/my_plus.c \
			src/my_printf_core.c \
			src/my_put_decimal.c \
			src/my_s.c \
			src/my_space.c \
			src/my_u.c \
			src/my_w.c \
			src/my_x.c \
			src/my_xx.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
