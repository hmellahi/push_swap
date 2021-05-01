SRC_FILES = inst.c rotate.c utils.c \
			double_linked_list.c push.c stack.c utils2.c \
			insertion_sort.c swap.c
push_swap = push_swap
checker = checker
push_swap : 
	gcc push_swap.c ${SRC_FILES} -D CHECKER=0 -fsanitize=address -o push_swap
checker : 
	gcc checker.c read_line.c utils3.c ${SRC_FILES} -D CHECKER=1 -fsanitize=address -o checker