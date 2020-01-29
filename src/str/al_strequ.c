#include "libal.h"

int	al_strequ(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if(s1 == NULL || s2 == NULL)
		return (0);
	while(s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] == s2[i]);
}

int	al_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if(s1 == NULL || s2 == NULL)
		return (0);
	while(s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i++;
	return (s1[i] == s2[i] || i == n);
}
