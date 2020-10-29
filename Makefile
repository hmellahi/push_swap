
.PHONEY: all clean fclean re bonus

NAME	= minishell

UTILS	=	#bintree.c linked_list.c num_tools_0.c str_tools_0.c\
			#str_tools_1.c str_tools_2.c gnl.c

PARSER	=	parser.c

DBG		=	MY_DBG.C my_dbg.h

SRC		=	$(PARSER:%.c=./src/parser/%.c)\
			$(UTILS:%.c=./src/utils/%.c)\

OBJ		=	$(PARSER:.c=.o)

CC		= gcc
FLAGS	= -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRC)
	@$(CC) $(OBJ) ./src/minishell.c -g -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@-rm -f *.out
	@-rm -f minishell
	@-rm -f *.gch
	@-rm -rf ./*.d*

re: fclean all

bu: fclean
	@bash git_bu.sh
