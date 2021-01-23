#include "libal.h"

char *al_strtolower(char *str)
{
	return al_strmap(str, &al_tolower);
}

char *al_strtoupper(char *str)
{
	return al_strmap(str, &al_toupper);
}


