#include "math.h"

float al_atof(char *str)
{
	float sign;
	float int_part;
	float decimal_pos;
	float decimal_part;
	
	sign = 1.;
	int_part = 0.;
	decimal_pos = 1;
	decimal_part = 0.;
	if(!str)
		return (0);
	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign = -1.;
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		int_part *= 10.;
		int_part += *str - '0';
		str++;
	}
	if(*str == '.')
		str++;
	while(*str >= '0' && *str <= '9')
	{
		decimal_pos /= 10.;
		decimal_part += decimal_pos * (*str - '0');
		str++;
	}
	return (sign * (int_part + decimal_part));	
}
