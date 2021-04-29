#include "checker.h"
 
 
void bubbleSort(t_node **headRef)
{
    t_node *itr;
    t_node *itr2;
    t_node *head;
    int *temp;

    head = *headRef;
    for(itr = head; itr->next != head; itr = itr->next) {
        for(itr2 = itr->next; itr2 != head; itr2 = itr2->next)
        {
            if(void_to_num(itr->data) > void_to_num(itr2->data))
            {
                temp = itr->data;
                itr->data = itr2->data;
                itr2->data = temp;
            }
        }
    }
}

