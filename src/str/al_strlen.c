#include "str.h"

size_t al_strlen(const char *src)
{
	size_t len;

	if(src == NULL)
		return (0);
	len = 0;
	while(src[len] != '\0')
	{
		len++;
	}
	return (len);
}
