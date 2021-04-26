#include "checker.h"

//is list empty
int isEmpty(t_node *head)
{
   return head == NULL;
}

void display_list(t_node *head, t_string type)
{
   t_node *ptr = head;
   ft_putstr("\n[ ");
   while (ptr != NULL)
   {
      if (strcmp(type, "int") == 0)
         ft_putnbr(ptr->num);
      else
         ft_putstr(ptr->word);
      ptr = ptr->next;
      ft_putstr("|");
      if (ptr == head)
         break;
   }
   ft_putstr(" ]\n");
}

void RightshiftList(t_node **head)
{
   (*head) = (*head)->next;
}

void LeftshiftList(t_node **head)
{
   (*head) = (*head)->prev;
}

void insertLast(t_node **head, void *data)
{
   t_node *link;

   link = (t_node *)malloc(sizeof(t_node));
   int i = void_to_num(data);
   link->data = data;
   link->prev = link;
   link->next = link;
   if (*head == NULL)
      *head = link;
   else
   {
      link->prev = (*head)->prev;
      link->next = *head;
      link->prev->next = link;
      (*head)->prev = link;
   }
}

t_node *deleteFirst(t_node **head)
{
   t_node *temp;

   temp = *head;
   if ((*head)->next == (*head))
   {
      (*head) = NULL;
      return NULL;
   }
   (*head)->next->prev = (*head)->prev;
   (*head)->prev->next = (*head)->next;
   (*head) = (*head)->next;
   return (temp);
}

char is_unique(t_stack *pt, void *data)
{
   int i;
   int last;
   t_node *curr;
   t_node *head;

   i = -1;
   head = pt->head;
   curr = head;
   while (1)
   {
      if (*((int *)curr->data) == *((int *)data))
         return (FALSE);
      curr = curr->next;
      if (curr == head)
         break;
   }
   return (TRUE);
}

t_node *get_index_of(t_stack *pt, void *data)
{
   int i;
   int last;
   t_node *curr;

   i = -1;
   curr = pt->head;
   while (1)
   {
      if (*((int *)curr->data) == *((int *)data))
         return (curr);
      curr = curr->next;
      if (curr == pt->head)
         break;
   }
   return (0);
}

t_node *get(t_stack *pt, void *index)
{
   int i;
   int last;
   t_node *curr;

   i = -1;
   curr = pt->head;
   while (index--)
      curr = curr->next;
   return (curr);
}