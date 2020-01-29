#include "str.h"

char	*al_strnew(size_t n)
{
	size_t	i;
	char 	*ret;

	ret = (char *)malloc(sizeof(char) * (n + 1));
	if(ret == NULL)
		return (NULL);
	i = 0;
	while(i <= n)
	{
			ret[i] = '\0';
			i++;
	}
	ret[i] = '\0';
	return (ret);

}
