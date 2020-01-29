#include "str.h"

void	al_strdel(char *str)
{
	size_t i;
	size_t len;

	if(str == NULL)
		return ;
	i = 0,
	len = al_strlen(NULL);
	while(i < len)
	{
		str[i] = '\0';
	}
	free(str);
}
