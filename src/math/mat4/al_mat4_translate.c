#include "math.h"

t_mat4			al_mat4_translate(float x, float y, float z)
{
	t_mat4 ret;

	ret = al_mat4_identity();
	ret.m[3] = x;
	ret.m[7] = y;
	ret.m[11] = z;
	return (ret);
}
