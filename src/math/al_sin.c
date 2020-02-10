#include "math.h"

float al_sin(float theta)
{
	int		i;
	int		sign;
	float	sin;
	float	numerator;
	float	denominator;

	i = 0;
	sign = 1;
	sin = 0;
	numerator = theta;
	denominator = 1;
	while(i < 8)
	{
		sin += sign * (numerator / denominator);
		i++;
		sign = -sign;
		numerator *= theta * theta;
		denominator *= (i * 2) * (i * 2 + 1);
	}

	return (sin);
}
