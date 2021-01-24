#include "libal.h"

int al_iseof(char c)
{
	return (c == '\n' || c == '\r');
}

int al_isalnum(char c)
{
	return (al_isalpha(c) || al_isdigit(c));
}

int al_isalpha(char c)
{
	return (al_isupper(c) || al_islower(c));
}

int al_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

int al_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int al_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int al_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

int al_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int al_isxdigit(char c)
{
	return (al_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

