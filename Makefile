
.PHONEY: all clean fclean re bonus

NAME		= 	minishell
CC			=	clang
FLAGS		= 	-Werror -Wextra -Wall

UTILS		=	#bintree.c linked_list.c num_tools_0.c str_tools_0.c\
				#str_tools_1.c str_tools_2.c gnl.c
TOKENIZER	=	quote_checker.c
LEXER		=	
PARSER		=	

DBG		=	MY_DBG.C my_dbg.h

SRC		=	src/minishell.c\
			$(PARSER:%.c=./src/parser/%.c)\
			$(UTILS:%.c=./src/utils/%.c)

OBJ		=	minishell.o\
			$(PARSER:.c=.o)\
			$(UTILS:.c=.o)

COMPILE	= $(CC) -I include -c $(SRC) #$(FLAGS)
LINK = $(CC) $(OBJ) -o $(NAME)  #$(FLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMPILE)
	@$(CC) $(OBJ) -Iinclude -g -o $(NAME)

$(OBJ): $(SRC)
	@$(COMPILE)

clean:
	@rm -rf *.o

fclean: clean
	@-rm -f $(NAME)
	@-rm -f *.out
	@-rm -f *.gch
	@-rm -rf ./*.d*

re: fclean all

bu: fclean
	@bash git_bu.sh
