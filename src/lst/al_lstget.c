#include "lst.h"

t_list	*al_lstget(t_list *begin, size_t n)
{
	size_t	i;
	t_list 	*lst;

	if(begin == NULL)
		return (NULL);
	i = 0;
	lst = begin;
	while(lst->next && i < n)
		lst = lst->next;
	return (lst);
}

t_list	*al_lstlast(t_list *begin)
{
	t_list 	*lst;

	if(begin == NULL)
		return (NULL);
	lst = begin;
	while(lst->next)
		lst = lst->next;
	return (lst);
}
