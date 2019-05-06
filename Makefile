##
## EPITECH PROJECT, 2019
## AIA_n4s_2018_tmp
## File description:
## Makefile
##

NAME	=	ai

SRC		=	src/main.c				\
			src/ll/node.c			\
			src/ll/setters.c		\
			src/ll/getters.c		\
			src/ll/list.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Iinclude
CLIBS	=	-lm


$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CLIBS)

all:	$(NAME)

debug:	CFLAGS += -g
debug:	fclean	all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)


re: fclean all