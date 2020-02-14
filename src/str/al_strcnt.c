#include "str.h"

int	al_strcnt(const char *str, char c)
{
	int     count;
	size_t  i;

	i = 0;
	count = 0;
	if(str == NULL)
		return (0);
	while(str[i] != '\0')
	{
		if(str[i] == c)
			count++;
		i++;
	}
	return (count);
}
