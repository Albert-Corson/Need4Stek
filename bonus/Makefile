##
## EPITECH PROJECT, 2019
## AIA_n4s_2018_tmp
## File description:
## Makefile
##

NAME	=	../train

SRC		=	../src/cmd/exec_cmd.c					\
			../src/cmd/api_res_parse.c				\
			../src/cmd/api_res_parse_data.c			\
			../src/cmd/api_res_parse_opt.c			\
			../src/tools/get_char_pos.c				\
			../src/tools/str_parse.c				\
			../src/tools/str_skip_chars.c			\
			../src/network/network.c				\
			../src/network/mx/mx.c					\
			../src/network/mx/mx_add.c				\
			../src/network/mx/mx_multiply.c			\
			../src/network/mx/mx_product.c			\
			../src/network/mx/mx_transpose.c		\
			../src/network/mx/mx_parse.c			\
			../src/network/tools/save.c				\
			../src/network/tools/restore.c			\
			../src/network/tools/forward.c			\
			../src/network/tools/randomize.c		\
			../src/network/tools/sigmoid.c			\
			../src/network/io/detect_collision.c	\
			../src/network/io/format_inputs.c		\
			../src/network/io/handle_outputs.c		\
			../src/backdoor/backdoor_ai_tools.c		\
			src/sample/sample.c						\
			src/sample/selection.c					\
			src/sample/breed.c						\
			src/sample/evolve.c						\
			src/sample/evaluate.c					\
			src/sample/save.c						\
			src/sample/restore.c					\
			src/simulation.c						\
			src/main.c								\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall -Iinclude -I../include -g
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

.PHONY: all debug clean fclean re