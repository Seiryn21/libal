#include "math.h"

t_vec3 al_vec3_crossproduct(t_vec3 a, t_vec3 b)
{
	float x;
	float y;
	float z;

	x = a.v[1] * b.v[2] - a.v[2] * b.v[1];
	y = a.v[2] * b.v[0] - a.v[0] * b.v[2];
	z = a.v[0] * b.v[1] - a.v[1] * b.v[0];
	return (al_vec3_init(x, y, z));
}

float al_vec3_dotproduct(t_vec3 a, t_vec3 b)
{
	return (a.v[0] * b.v[0] + a.v[1] * b.v[1] + a.v[2] * b.v[2]);
}
