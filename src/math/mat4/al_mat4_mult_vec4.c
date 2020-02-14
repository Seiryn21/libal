#include "math.h"

t_vec4			al_mat4_mult_vec4(t_mat4 mat, t_vec4 vec)
{
	int	i;
	int	j;
	t_vec4 ret;

	i = 0;
	while(i < 4)
	{
		j = 0;
		ret.v[i] = 0;
		while(j < 4)
		{
			ret.v[i] += mat.m[j + i * 4] * vec.v[j];
			j++;
		}
		i++;
	}
	return (ret);
}
