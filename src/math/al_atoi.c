#include "math.h"

int al_atoi(char *str)
{
	int sign;
	int value;

	sign = 1;
	value = 0;
	if(!str)
		return (0);
	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign = -1;
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	return (sign * value);
}

