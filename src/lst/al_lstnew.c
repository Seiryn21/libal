#include "lst.h"

t_list	*al_lstnew(void *const content, size_t content_size)
{
	t_list 	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if(new == NULL)
		return (NULL);
	new->next = NULL;
	new->content = al_memalloc(content_size + 1);
	new->content = al_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}

t_list	*al_lstnew_ptr(void *const content)
{
	t_list 	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if(new == NULL)
		return (NULL);
	new->next = NULL;
	new->content = content;
	new->content_size = sizeof(void*);
	return (new);
}
