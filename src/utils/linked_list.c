
#include "minishell.h"

t_node  *new_node(void *data)
{
    t_node *node;

    //node = malloc(sizeof(node));
    MALLOC(node);
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

void    push_back(LIST, void  *data)
{
    t_node      *iter;

    iter = *list;
    while (iter)
        iter = iter->next;
    iter = new_node(data);
    if (!iter)
        return ;
}

void    push_front(LIST, void  *data)
{
    t_node      *new;

    if (NOT *list)
        *list = new_node(data);
    else
    {
        new = new_node(data);
        if (NOT new)
            return ;
        new->next = *list;
        *list = new;
    }
}

void    list_iter(LIST, void(*fun)(void **))
{
    t_node      *tmp;

    if (*list == NULL)
        return ;
    tmp = *list;
    while (tmp != NULL)
    {
        (fun)(&tmp->data);
        tmp = tmp->next;
    }
}

void    clear_list(LIST)
{
    void    *(fun);
    fun = safe_free;
    list_iter(list, fun);
    //fun = destroy_lst;
    //list_iter(list, fun);
}

size_t  list_size(t_node    *list)
{
    t_node  *tmp;
    size_t  i;
    
    if (list == NULL)
        return (0);
    tmp = list;
    i = 0;
    while (tmp != NULL)
    {
        print((char*)tmp->data);
        tmp = tmp->next;
        i++;
    }
    return (i);
}

void	safe_free(void **p)
{
	if (*p != NULL)
    //if (p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void    destroy_lst(LIST)
{
    t_node      *p1;
    t_node      *p2;

    if (*list == NULL)
        return ;
	p1 = *list;
    while (p1 != NULL)
    {
		p2 = p1->next;
		safe_free((void **)&p1);
		p1 = p2;
    }
	//safe_free(tmp);
}

void	delete_lst(LIST) 
{ 
   t_node *current;
   t_node *next;
   
   current = *list; 
   while (current != NULL)  
   { 
       next = current->next; 
       safe_free((void **)&current);
       current = next; 
   } 
   *list = NULL; 
} 