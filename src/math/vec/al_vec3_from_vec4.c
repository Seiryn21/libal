#include "math.h"

t_vec3	al_vec3_from_vec4(t_vec4 a)
{
	t_vec3 ret;

	ret.v[0] = a.v[0] / al_abs(a.v[3]);
	ret.v[1] = a.v[1] / al_abs(a.v[3]);
	ret.v[2] = a.v[2] / al_abs(a.v[3]);
	return (ret);
}
