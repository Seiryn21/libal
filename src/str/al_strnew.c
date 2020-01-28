#include "libal.h"

char	*al_strnew(size_t n)
{
	size_t	i;
	char 	*ret;
	ret = (char *)malloc(sizeof(char) * n);
	if(ret == NULL)
		return (NULL);
	while(i < n)
	{
			ret[i] = '\0';
			i++;
	}
	return (ret);

}
