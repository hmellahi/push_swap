SRC_FILES = inst.c rotate.c utils.c \
			double_linked_list.c push.c stack.c utils2.c \
			insertion_sort.c swap.c sorting.c reading.c \
			free_list.c get_list.c display_list.c delete_list.c \
			rev_rotate.c stack2.c utils3.c
push_swap = push_swap
checker = checker
FLAGS = -Wall -Werror -Wextra #-g #-fsanitize=address 
push_swap :
	gcc push_swap.c ${FLAGS} ${SRC_FILES} -D CHECKER=0 -o push_swap
checker : 
	gcc checker.c read_line.c ${SRC_FILES} -D CHECKER=1 -o checker