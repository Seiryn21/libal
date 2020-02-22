#include "str.h"

char	*al_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*ret;

	len1 = al_strlen(s1);
	len2 = al_strlen(s2);
	ret = al_strnew(len1 + len2);
	al_strcpy(ret, s1);
	al_strcpy(ret + len1, s2);
	return (ret);
}
