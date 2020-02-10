#include "math.h"

static float	al_mat4_mult_coef(t_mat4 a, t_mat4 b, int line, int column)
{
	int i;
	float sum;

	i = 0;
	sum = 0;
	while(i < 4)
	{
		sum += a.m[i + line * 4] * b.m[column + i * 4];
		i++;
	}

	return (sum);
}

t_mat4 			al_mat4_mult(t_mat4 a, t_mat4 b)
{
	int		i;
	int		j;
	t_mat4 	ret;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			ret.m[i + j * 4] = al_mat4_mult_coef(a, b, j, i);
			j++;
		}
		i++;
	}
	return (ret);
}
