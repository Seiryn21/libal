#include "math.h"

t_mat4 al_mat4_empty()
{
	int		i;
	t_mat4	ret;

	i = 0;
	while(i < 16)
	{
		ret.m[i] = 0;
		i++;
	}
	return (ret);
}

t_mat4 al_mat4_identity()
{
	int		i;
	t_mat4	ret;

	i = 0;
	ret = al_mat4_empty();
	while(i < 4)
	{
		ret.m[i + i * 4] = 0;
		i++;
	}
	return (ret);
}
