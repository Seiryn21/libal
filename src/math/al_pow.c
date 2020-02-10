#include "math.h"

float al_pow(float nbr, int n)
{
	int i;
	float ret;

	i = 0;
	ret = 1;
	while(i < n)
	{
		ret *= nbr;
		i++;
	}
	return (ret);
}
