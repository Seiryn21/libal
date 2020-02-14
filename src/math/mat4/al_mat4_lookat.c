#include "math.h"

t_mat4 al_mat4_lookat(t_vec3 from, t_vec3 to)
{
	int		i;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	top;
	t_mat4	ret;

	i = 0;
	ret = al_mat4_identity();
	forward = al_vec3_norm(al_vec3_sub(from, to));
	right = al_vec3_norm(al_vec3_crossproduct(al_vec3_init(0, 1, 0), forward));
	top = al_vec3_norm(al_vec3_crossproduct(forward, right));
	while(i < 3)
	{
		ret.m[i * 4] = right.v[i];
		ret.m[1 + i * 4] = top.v[i];
		ret.m[2 + i * 4] = forward.v[i];
		i++;
	}
	ret.m[3] = -al_vec3_dotproduct(right, from);
	ret.m[7] = -al_vec3_dotproduct(top, from);
	ret.m[11] = -al_vec3_dotproduct(forward, from);
	return (ret);
}
