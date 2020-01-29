#include "mem.h"

void	*al_memcpy(void *dest,const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;

	i = 0;
	tmp_src = (unsigned char*)src;
	tmp_dest = (unsigned char*)dest;
	if(dest == NULL || src == NULL)
		return (dest);
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}
