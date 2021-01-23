#include "libal.h"

char *al_strmap(char *str, char (*f)(char))
{
	int i;

	i = 0;
	while(str[i])
	{
		str[i] = f(str[i]);
		i++;
	}
	return (str);
}
