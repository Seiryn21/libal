#include "str.h"

char *al_strchr(const char *str, char c)
{
	char *tmp;

	if(str == NULL)
		return (NULL);
	tmp = (char *)str;
	while(*tmp != '\0' && *tmp != c)
		tmp++;
	if(*tmp == c)
		return (tmp);
	return (NULL);
}

char *al_strrchr(const char *str, char c)
{
	char *tmp;
	char *last;	

	if(str == NULL)
		return (NULL);
	tmp = (char *)str;
	last = NULL;
	while(*tmp != '\0')
	{
		if(*tmp == c)
			last = tmp;
		tmp++;
	}
	if(*tmp == c)
		last = tmp;
	return (last);
}
