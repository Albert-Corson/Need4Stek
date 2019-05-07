##
## EPITECH PROJECT, 2019
## AIA_n4s_2018_tmp
## File description:
## Makefile
##

NAME	=	ai

SRC		=	src/main.c							\
			src/cmd/exec_cmd.c					\
			src/cmd/api_res_parse_info.c		\
			src/cmd/api_res_parse_data.c		\
			src/cmd/api_res_parse_opt.c			\
			src/ll/node.c						\
			src/ll/list.c						\
			src/tools/str_parse.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall -Iinclude -g
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