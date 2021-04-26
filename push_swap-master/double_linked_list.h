#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
typedef char* t_string;

typedef struct s_node {
   enum { INT, CHAR} type;
   union {
      int num;
      char *word;
   };
   struct s_node *next;
   struct s_node *prev;
}               t_node;

void insertLast(t_node **head,void* data);
void RightshiftList(t_node **head);
void  LeftshiftList(t_node **head);
void insertFirst(t_node *head,t_node *last, void* data);
void display_list(t_node *head, t_string type);
t_node* SortedMerge(t_node* a, t_node* b);
void FrontBackSplit(t_node* source,
t_node** frontRef, t_node** backRef);
t_node* deleteFirst(t_node **head);
void merge_sort(t_node** headRef);
t_node *get(t_stack *pt, void *index);

#endif