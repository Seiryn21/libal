#include "math.h"

t_mat4 al_mat4_scale(t_vec3 scale)
{
	t_mat4 ret;

	ret = al_mat4_empty();
	ret.m[0] = scale.v[0];
	ret.m[5] = scale.v[1];
	ret.m[10] = scale.v[2];
	ret.m[15] = 1;

	return (ret);
}
