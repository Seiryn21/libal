#include "lst.h"

void	al_lstadd(t_list **begin, t_list *new)
{
	if(begin == NULL || new == NULL)
		return ;
	new->next = *begin;
	*begin = new;
}

void	al_lsteadd(t_list **begin, t_list *new)
{
	t_list	*lst;

	if(begin == NULL || new == NULL)
		return ;
	lst = *begin;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*begin = new;
}

void	al_lstnadd(t_list **begin, t_list *new, size_t n)
{
	size_t	i;
	t_list	*next;
	t_list	*before;

	if(begin == NULL || new == NULL)
		return ;
	i = 0;
	next = *begin;
	before = NULL;
	if (next)
	{
		while (next && i < n)
		{
			before = next;
			next = next->next;
			i++;
		}
		if(before != NULL)
			before->next = new;
		new->next = next;
	}
	else
		*begin = new;
}
