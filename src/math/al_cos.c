#include "math.h"

float al_cos(float theta)
{
	int		i;
	int		sign;
	float	cos;
	float	numerator;
	float	denominator;

	i = 0;
	sign = 1;
	cos = 0;
	numerator = 1;
	denominator = 1;
	while(i < 8)
	{
		cos += sign * (numerator / denominator);
		i++;
		sign = -sign;
		numerator *= theta * theta;
		denominator *= (i * 2 - 1) * (i * 2);
	}

	return (cos);
}
