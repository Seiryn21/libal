#include "math.h"

t_vec4	al_vec4_from_vec3(t_vec3 a)
{
	t_vec4 ret;

	ret.v[0] = a.v[0];
	ret.v[1] = a.v[1];
	ret.v[2] = a.v[2];
	ret.v[3] = 1;

	return (ret);
}
