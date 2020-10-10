#include "math.h"

char *al_itoa(int nbr)
{
	int sign;
	int len;
	int tmp;
	char *ret;

	len = 0;
	sign = 1;
	tmp = nbr;
	if(tmp < 0)
	{
		sign = -1;
		len++;
	}
	while(tmp > 10 || tmp < -10)
	{
		len++;
		tmp /= 10;
	}
	if((ret = al_strnew(len + 1)) == NULL)
		return (NULL);
	if(nbr < 0)
		ret[0] = '-';
	while(nbr > 10 || nbr < -10)
	{
		ret[len] = '0' + (nbr % 10) * sign;
		len--;
		nbr /= 10;
	}
	ret[len] = '0' + (nbr % 10) * sign;
	return  (ret);
}
