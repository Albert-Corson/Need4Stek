##
## EPITECH PROJECT, 2019
## AIA_n4s_2018_tmp
## File description:
## Makefile
##

NAME	=	ai

SRC		=	src/main.c							\
			src/cmd/exec_cmd.c					\
			src/cmd/api_res_parse.c				\
			src/cmd/api_res_parse_data.c		\
			src/cmd/api_res_parse_opt.c			\
			src/tools/get_char_pos.c			\
			src/tools/str_parse.c				\
			src/tools/str_skip_chars.c			\
			src/network/network.c				\
			src/network/mx/mx.c					\
			src/network/mx/mx_add.c				\
			src/network/mx/mx_multiply.c		\
			src/network/mx/mx_product.c			\
			src/network/mx/mx_transpose.c		\
			src/network/mx/mx_parse.c			\
			src/network/tools/save.c			\
			src/network/tools/restore.c			\
			src/network/tools/forward.c			\
			src/network/tools/randomize.c		\
			src/network/tools/sigmoid.c			\
			src/network/io/detect_collision.c	\
			src/network/io/format_inputs.c		\
			src/network/io/handle_outputs.c		\
			src/backdoor/backdoor_ai.c			\
			src/backdoor/backdoor_main.c		\
			src/backdoor/backdoor_ai_tools.c	\

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
	make clean -C bonus

fclean:	clean
	rm -f $(NAME)
	make fclean -C bonus

re: fclean all

train:
	make -C bonus

.PHONY: all debug clean fclean re train