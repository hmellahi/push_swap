
.PHONEY: all clean fclean re bonus

NAME			= 	minishell
CC				=	clang
FLAGS			= 	-Werror -Wextra -Wall
UTILS			=	get_line.c strtools_0.c strtools_1.c strtools_2.c
					#num_tools_0.c\
					#bintree.c linked_list.c

CONSTRUCTORS	=	env.c
TOKENIZER		=	quote_checker.c
LEXER			=	
PARSER			=	
EXECUTER		=	

DBG				=	MY_DBG.C my_dbg.h

SRC				=	src/minishell.c\
					$(PARSER:%.c=./src/parser/%.c)\
					$(UTILS:%.c=./src/utils/%.c)\
					$(CONSTRUCTORS:%.c=./src/constructors/%.c)

OBJ				=	minishell.o\
					$(PARSER:.c=.o)\
					$(CONSTRUCTORS:.c=.o)\
					$(UTILS:.c=.o)

## For debuging:
################
DBG_FLAGS		=  -g 

###################

COMPILE	= $(CC) -I include -c $(SRC) #$(DBG_FLAGS)
LINK = $(CC) $(OBJ) -o $(NAME)  #$(DBG_FLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMPILE)
	@$(CC) $(OBJ) -Iinclude -o $(NAME)

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
