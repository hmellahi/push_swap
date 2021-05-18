/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:01:50 by hamza             #+#    #+#             */
/*   Updated: 2021/05/15 14:45:46 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H
# include <stdbool.h>
typedef char*	t_string;

enum e_Types {INT, CHAR};
typedef struct s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

void	insertLast(t_node **head, void *data);
void	RightshiftList(t_node **head);
void	LeftshiftList(t_node **head);
void	freeList(t_node **head);
void	insertFirst(t_node **head, void *data);
void	display_list(t_node *head, int type);
t_node	*SortedMerge(t_node *a, t_node *b);
void	FrontBackSplit(t_node *source,
			t_node **frontRef, t_node **backRef);
t_node	*deletefirst(t_node **head);
void	merge_sort(t_node **headRef);
t_node	*deleteLast(t_node **head);
void	bubble_sort(t_node **headRef);
int		get_index_of(t_node *pt, void *data);
#endif