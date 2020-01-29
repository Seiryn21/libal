#include "libal.h"

char	*al_strdup(const char *src)
{
	char	*ret;

	if(src == NULL)
		return (NULL);
	ret = al_strnew(al_strlen(src) + 1);
	return (al_strcpy(ret, src));
}
