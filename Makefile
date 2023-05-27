##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##
NAME	=	push_swap

CC		=	gcc -g3
RM		=	rm -rf

SRC		=	$(shell find src -type f -name "*.c")

OBJ		=	$(SRC:.c=.o)

L_FLAGS	=	-Llib/my -lmy -Iinclude
CFLAGS	=	-W -Wall -Wextra

$(NAME):
		make -C lib/my
		$(CC) -o $(NAME) $(SRC) $(L_FLAGS) $(CFLAGS)
		rm lib/libmy.a
		rm lib/my/libmy.a
		make clean

all:	$(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
