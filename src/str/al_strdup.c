#include "str.h"

char	*al_strdup(const char *src)
{
	char	*ret;

	if(src == NULL)
		return (NULL);
	ret = al_strnew(al_strlen(src) + 1);
	return (al_strcpy(ret, src));
}

char	*al_strndup(const char *src, size_t n)
{
	char	*ret;

	ret = al_strnew(n + 1);
	if(src == NULL)
		return (ret);
	return (al_strncpy(ret, src, n));
}
