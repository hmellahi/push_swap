#include "checker.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

t_string    inst_list[11] = {
    "sa",
    "sb",
    "ss",
    "pa",
    "pb",
    "ra",
    "rb",
    "rr",
    "rra",
    "rrb",
    "rrr"
};

void insertionSort(int arr[], int n)
{
    int i, key, j;

    i = -1;
    while (++i < n)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int     (*run_inst(int index)) (t_stack *fs, t_stack *ss)
{
    int    (*funcs[12])(t_stack *fs, t_stack *ss);
    
    funcs[0] = swap_list_a;
    funcs[1] = swap_list_b;
    funcs[2] = swap_both;
    funcs[3] = push_in_a;
    funcs[4] = push_in_b;
    funcs[5] = rotate_a;
    funcs[6] = rotate_b;
    funcs[7] = rotate_both;
    funcs[8] = rev_rotate_a;
    funcs[9] = rev_rotate_b;
    funcs[10] = rev_rotate_both;
    funcs[11] = NULL;
    return funcs[index];
}

int    exect_inst(t_stack *fs, t_stack *ss, t_string inst)
{
    int index;
    
    index = -1;
    while(++index < 11)
        if (strcmp(inst_list[index], inst) == 0)
        {
            (run_inst(index))(fs, ss);
            return (TRUE);
        }
    printf("Error\n");
    return (FALSE);
}

void    repeat_n_times(int (*func)(), t_stack *a , int n)
{
    while(n--)
        func(a);
}

void    move_to_top(t_stack *list, int index)
{
    int moves;

    moves = list->size - index;
    if (moves > 0)
        repeat_n_times(rotate_a, list, moves);
    else
        repeat_n_times(rev_rotate, list, -moves);
}

int    ft_exit(int status)
{
    ft_putstr("Error\n");
    // free garbage [TODO]
    exit(status);
}

int main(int ac, char** av)
{
    // int i;
    int j;
    int x;
    t_stack *list_a;
    t_stack *list_b;

    list_a = newStack(ac);
    list_b = newStack(0);
   // while (++i < ac)
    // {
    //     j = -1;
    //     while (++j < strlen(av[i]))
    //     {
    //         x = av[i][j];
    //         if (!is_digit(x))
    //             return(ft_exit(ERROR));
    //     }
    //     // if (!is_unique(list_a, av + i))
    //     //     return(ft_exit(ERROR));
    //     x = atoi(av[i]);
    //     push(list_a, &x);
    // }
    char *s = "ss";
    char *d = 
    push(list_a, s);
    push(list_a, s);
    push(list_a, b);
    display(list_a);
    // int chunk_index = 1;
    // int half = ac / 2;
    // int chunk_size = ac / 5;
    // int i = -1;
    // int index,min1,min2;
    // int hold_first_index = -1;
    // int hold_sec_index = -1;
    // t_node *sortedList = ;
    // merge_sort(&(list_a->head));
    // while (chunk_index < 5)
    // {
    //     int max_of_cc = get(sorted_list, chunk_index * chunk_size);
    //     while (++i < ac)
    //     {
    //         int x = void_to_num(list_a->);
    //         if (x < max_of_cc)
    //             hold_first_index = x;
    //     }
    //     i = ac;
    //     while (i-- > hold_first_index)
    //         if (list[i] < max_of_cc)
    //             hold_sec_index = i;
    //     if (hold_first_index)
    //         min1 = (ac / 2) - hold_first_index;
    //     if (hold_sec_index)
    //         min2 = (ac / 2) - hold_sec_index;
    //     if (hold_first_index || hold_sec_index)
    //     {
    //         index = min1 > min2 ? hold_sec_index : hold_first_index;
    //         move_to_top(list_a, hold_first_index);
    //         push_to_a(list_a, hold_first_index);
    //     }
    //     // do
    //     chunk_index++;
    // }
    // i = -1;
    // int max;
    // while (++i < ac)
    // {
    //     max = sorted_list[ac - i];
    //     while (list_b->next != list->head)
    //     {
    //         if (list_b->data = max)
    //         {
    //             move_to_top(list_b, max);
    //             push_to_a(list_a, max);
    //             break;
    //         }
    //         list_b = list_b->next;
    //     }
    // }
}