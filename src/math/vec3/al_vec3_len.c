#include "math.h"

float al_vec3_len(t_vec3 a)
{
	float ret;

	ret = al_sqrt(a.v[0] * a.v[0] + a.v[1] * a.v[1] + a.v[1] * a.v[1]);
	return (ret);
}
