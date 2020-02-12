#include "math.h"

t_vec3	al_vec3_mult(t_vec3 a, float n)
{
	t_vec3 ret;

	ret.v[0] = n * a.v[0];
	ret.v[1] = n * a.v[1];
	ret.v[2] = n * a.v[2];
	return (ret);
}
