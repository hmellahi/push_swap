#include "checker.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

t_string inst_list[11] = {
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
    "rrr"};

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

int (*run_inst(int index))(t_stack *fs, t_stack *ss)
{
    int (*funcs[12])(t_stack * fs, t_stack * ss);

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

int exect_inst(t_stack *fs, t_stack *ss, t_string inst)
{
    int index;

    index = -1;
    while (++index < 11)
        if (strcmp(inst_list[index], inst) == 0)
        {
            (run_inst(index))(fs, ss);
            return (TRUE);
        }
    printf("Error\n");
    return (FALSE);
}

void repeat_n_times(int (*func)(), t_stack *a, int n)
{
    while (n--)
        func(a);
}

void move_to_top(t_stack *a,int index)
{
    int moves;

    moves = index;
    if (moves > 0)
        repeat_n_times(rotate, a, moves);
    else
        repeat_n_times(rev_rotate, a, -moves);
}

int ft_exit(int status)
{
    if (status == ERROR)
        ft_putstr("Error\n");
    // free garbage [TODO]
    exit(status);
}

int main(int ac, char **av)
{
    int i;
    int j;
    int x;
    int *k;
    t_stack *list_a;
    t_stack *list_b;

    list_a = newStack();
    list_b = newStack();
    i = 0;
    ac--;
    if (ac == 0)
        return (ft_exit(ERROR));
    while (++i <= ac)
    {
        j = -1;
        while (++j < strlen(av[i]))
        {
            x = av[i][j];
            if (!is_digit(x))
                return (ft_exit(ERROR));
        }
        k = malloc(sizeof(int));
        *k = atoi(av[i]);
        if (!is_unique(list_a, k))
            return (ft_exit(ERROR));
        push(list_a, k);
    }
    int chunk_index = 0;
    int half = list_a->size / 2;
    int chunk_size = list_a->size / 4 ;
    int index,min1,min2, hold_first, hold_sec;
    int hold_first_index = 9999;
    int hold_sec_index = 9999;
    t_stack *sorted_list = cpy(list_a);
    bubbleSort(&sorted_list->head);
    display(sorted_list);
    while (!is_empty(list_a))
    {
        int max_of_cc = void_to_num(get(sorted_list, chunk_index * chunk_size)->data);
        half = list_a->size / 2;
        i = -1;
        while (++i < list_a->size)
        {
            x = void_to_num(get(list_a, i)->data);
            if (x <= max_of_cc)
            {
                hold_first_index = i;
                hold_first = x;
                break;
            }
        }
        i = list_a->size;
        while (--i > hold_first_index)
        {
            x = void_to_num(get(list_a, i)->data);
            if (x <= max_of_cc)
            {
                hold_sec_index = i;
                hold_sec = x;
                break;
            }
        }
        if (hold_first_index != 9999)
        {
            if (hold_first_index > half)
                min1 = hold_first_index - list_a->size;
            else
                min1 = hold_first_index;
        }
        if (hold_sec_index != 9999)
        {
            if (hold_sec_index > half)
                min2 = hold_sec_index - list_a->size;
            else
                min2 = hold_sec_index;
        }
        index = abs(min1) > abs(min2) ? min2 : min1;
        move_to_top(list_a, index);
        if (!is_empty(list_a) && is_equal(sorted_list, list_a) == TRUE)
            return (ft_exit(COMPLETED));
        push_in_b(list_a, list_b);
        //display(list_a);
        //printf("moved to top : %d\n", abs(min1) > abs(min2)? hold_sec_index: hold_first_index);
        chunk_index++;
    }
    // puts("a : after");
    // //display(list_a);
    // puts("b : after");
    // //display(list_b);
    // int max;
    // t_node *curr;
    // curr = list_b->head;
    // while (!is_empty(list_b))
    // {
    //     i = 0;
    //     max = void_to_num(get(sorted_list, ac - 1)->data);
    //     while (1)
    //     {
    //         if (void_to_num(curr->data) == max)
    //         {
    //             move_to_top(list_b, (ac /2) - i);
    //             push_in_a(list_a, list_b);
    //             break;
    //         }
    //         curr = curr->next;
    //         i++;
    //         if (curr == list_b->head)
    //             break;
    //     }
    // }
    //puts("a : after");
    //display(list_a);
    //puts("b : after");
    //display(list_b);
}