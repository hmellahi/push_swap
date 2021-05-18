SRC_FILES = rotate.c utils.c \
			double_linked_list.c push.c stack.c utils2.c \
			insertion_sort.c swap.c sorting.c reading.c \
			free_list.c get_list.c display_list.c delete_list.c \
			rev_rotate.c stack2.c utils3.c
push_swap = push_swap
checker = checker
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address 
CHECKER_FILES = checker.c read_line.c inst.c 

all : {push_swap}

clean :
	rm -rf push_swap

fclean : clean
	rm -rf ${checker}

re : fclean all

{push_swap} :
	gcc push_swap.c ${FLAGS} ${SRC_FILES} -D CHECKER=0 -o push_swap

checker :
	gcc ${CHECKER_FILES} ${FLAGS}  ${SRC_FILES} -D CHECKER=1 -o checker