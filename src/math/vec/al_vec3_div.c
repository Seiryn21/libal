#include "math.h"

t_vec3	al_vec3_div(t_vec3 a, float n)
{
	t_vec3 ret;

	ret.v[0] = a.v[0] / n;
	ret.v[1] = a.v[1] / n;
	ret.v[2] = a.v[2] / n;
	return (ret);
}
