#include "libal.h"

char al_tolower(char c)
{
	return (al_isupper(c) ? c + 32 : c );
}

char al_toupper(char c)
{
	return (al_islower(c) ? c - 32 : c);
}
