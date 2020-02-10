#include "math.h"

t_vec3	al_vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3 ret;

	ret.v[0] = a.v[0] + b.v[0];
	ret.v[1] = a.v[1] + b.v[1];
	ret.v[2] = a.v[2] + b.v[2];
	return (ret);
}
