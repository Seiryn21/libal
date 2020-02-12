#include "math.h"

t_vec3 al_vec3_init(float x, float y,  float z)
{
	t_vec3 ret;

	ret.v[0] = x;
	ret.v[1] = y;
	ret.v[2] = z;

	return (ret);
}
