#include "str.h"

char	*al_strcat(char *dest, const char *src)
{
	size_t i;

	if(dest == NULL || src == NULL)
		return (dest);
	i = al_strlen(dest);
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*al_strncat(char *dest, const char *src, size_t n)
{
	size_t i;

	if(dest == NULL || src == NULL)
		return (dest);
	i = al_strlen(dest);
	while(src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
