#include "mem.h"

void	*al_memset(void *mem, int c, size_t n)
{
	size_t i;

	i = 0;
	if(mem != NULL)
	{
		while(i < n)
		{
			((char*)(mem))[i] = c;
			i++;
		}
	}
	return (mem);
}

void	al_bzero(void *mem, size_t n)
{
	al_memset(mem, 0, n);
}
