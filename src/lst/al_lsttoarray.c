#include "lst.h"

void **al_lsttoarray(t_list *begin)
{
	int i;
	int len;
	void **array;
	
	i = 0;
	len = al_lstlen(begin);
	array = al_memalloc((len + 1) * sizeof(void*));
	if(array == NULL)
		return (NULL);
	while(begin)
	{
		array[i] = begin->content;
		i++;
		begin = begin->next;
	}
	return (array);
}

