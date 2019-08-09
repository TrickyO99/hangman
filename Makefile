##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c		\
		src/dictionary.c	\
		src/game_loop.c		\
		src/star_to_char.c	\
		src/is_star_in_src.c

OBJ	=	$(SRC:.c=.o)

NAME	=	hangman

CFLAGS	=	-I./include

all	:	$(NAME) clean

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
		@echo "Compil : done"

clean	:
		rm -f $(OBJ)
		@echo "Clean : done"

fclean	:	clean
		rm -f $(NAME)
		@echo "Fclean : done"

re	:	fclean all

.phony	:	all clean fclean re
