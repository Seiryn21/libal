#include "math.h"

t_vec3	al_vec3_norm(t_vec3 a)
{
	float len;

	len = al_vec3_len(a);
	return (al_vec3_div(a, len));
}
