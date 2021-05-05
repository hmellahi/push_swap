/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:21:26 by hamza             #+#    #+#             */
/*   Updated: 2021/05/04 06:24:15 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void insertFirst(t_node **head, void *data)
{
   t_node *link;

   link = (t_node *)malloc(sizeof(t_node));
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
      *head = link;
   }
}

char is_unique(t_stack *pt, void *data)
{
   t_node *curr;

   curr = pt->head;
   while (curr != NULL)
   {
      if (void_to_num(curr->data) == void_to_num(data))
         return (FALSE);
      curr = curr->next;
      if (curr == pt->head)
         break;
   }
   return (TRUE);
}