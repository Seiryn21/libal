#include "mem.h"

void	al_memdel(void *mem, size_t n)
{
	size_t i;
	unsigned char *tmp;

	i = 0;
	tmp = (unsigned char*)mem;
	if(mem == NULL)
		return ;
	while(i < n)
	{
		tmp[i] = 0;
		i++;
	}
	free(mem);
}
