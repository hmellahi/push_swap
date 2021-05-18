ARG=$("2 1 0"); ./push_swap $ARG | ./checker_Mac $ARG #2/3
ARG=$("1 5 2 4 3"); ./push_swap $ARG | ./checker_Mac $ARG #12
./push_swap 42 # none
./push_swap 0 1 2 3 # none
./push_swap 0 1 2 3 4 5 6 7 8 9 # none