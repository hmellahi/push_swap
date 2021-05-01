run :
	gcc *.c -fsanitize=address -o push_swap && ./push_swap 1 2 3 4