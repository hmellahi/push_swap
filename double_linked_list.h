#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
typedef char* t_string;

enum Types {INT, CHAR};
typedef struct s_node {
   //int            type;
   void           *data;

   struct s_node *next;
   struct s_node *prev;
}               t_node;

void insertLast(t_node **head,void* data);
void RightshiftList(t_node **head);
void  LeftshiftList(t_node **head);
void  freeList(t_node **head);
void insertFirst(t_node **head, void *data);
void display_list(t_node *head, int type);
t_node* SortedMerge(t_node* a, t_node* b);
void FrontBackSplit(t_node* source,
t_node** frontRef, t_node** backRef);
t_node* deleteFirst(t_node **head);
void merge_sort(t_node** headRef);
t_node *deleteLast(t_node **head);
void bubbleSort(t_node **headRef);
#endif