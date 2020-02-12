#include "math.h"

t_mat4	al_mat4_translate(t_vec3 pos)
{
	t_mat4 ret;

	ret = al_mat4_identity();
	ret.m[3] = pos.v[0];
	ret.m[7] = pos.v[1];
	ret.m[11] = pos.v[2];
	return (ret);
}
