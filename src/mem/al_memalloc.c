#include "mem.h"

void 	*al_memalloc(size_t n)
{
	size_t			i;
	unsigned char*	new;

	i = 0;
	new = malloc(n);
	if(new == NULL)
		return (NULL);
	while(i < n)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
