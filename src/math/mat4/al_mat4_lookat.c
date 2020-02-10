#include "math.h"

t_mat4 al_mat4_lookat(t_vec3 from, t_vec3 to)
{
	int		i;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	top;
	t_mat4	ret;

	i = 0;
	ret = al_mat4_empty();
	forward = al_vec3_norm(al_vec3_sub(from, to));
	right = al_vec3_norm(al_vec3_crossproduct(al_vec3_init(0, 1, 0), right));
	top = al_vec3_norm(al_vec3_crossproduct(forward, right));
	while(i < 3)
	{
		ret.m[i] = right.v[i];
		ret.m[i + 4] = top.v[i];
		ret.m[i + 8] = forward.v[i];
		ret.m[i + 12] = from.v[i];
		i++;
	}
	return (ret);
}
