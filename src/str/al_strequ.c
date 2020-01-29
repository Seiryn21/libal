#include "libal.h"

int	al_strequ(const char *s1, const char *s2)
{
	return (al_strcmp(s1, s2) == 0);
}

int	al_strnequ(const char *s1, const char *s2, size_t n)
{
	return (al_strncmp(s1, s2, n) == 0);
}
