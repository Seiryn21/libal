#include "libal.h"

char	*al_strcpy(char *dest, const char *src)
{
	size_t	i;

	if(dest == NULL || src == NULL)
		return (dest);
	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*al_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if(dest == NULL || src == NULL)
		return (dest);
	i = 0;
	while(src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while(i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
