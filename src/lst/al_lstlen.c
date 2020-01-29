#include "lst.h"

int		al_lstlen(t_list *begin)
{
	int		len;
	t_list	*lst;

	if(begin == NULL)
		return 0;
	len = 0;
	lst = begin;
	while(lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
