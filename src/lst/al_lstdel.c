#include "lst.h"

void	al_lstdel(t_list **begin, void (*del)(void *, size_t))
{
	if(begin == NULL)
		return;
	while(*begin)
	{
		al_lstdel_one(begin, del);
	}
}

void	al_lstdel_one(t_list **begin, void (*del)(void *, size_t))
{
	t_list *tmp;

	if(begin == NULL || *begin == NULL)
		return;
	tmp = *begin;
	*begin = tmp->next;
	if(del)
		del(tmp->content, tmp->content_size);
	free(tmp);
}

