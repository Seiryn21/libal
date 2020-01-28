#include "libal.h"

char	*al_strdup(const char *src)
{
	char	*ret;

	ret = al_strnew(al_strlen(src) + 1);
	if(ret == NULL)
		return (NULL);
	return (al_strcpy(ret, src));
}
