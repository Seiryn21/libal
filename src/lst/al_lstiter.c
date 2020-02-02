#include "lst.h"

void	al_lstiter(t_list *begin, void (*iter)(void *, size_t))
{
	t_list *lst;

	if(begin == NULL)
		return;
	lst = begin;
	while(lst)
	{
		iter(lst->content, lst->content_size);
		lst = lst->next;
	}
}
