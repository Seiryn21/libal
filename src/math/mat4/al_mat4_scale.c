#include "math.h"

t_mat4 al_mat4_scale(float x, float y, float z)
{
	t_mat4 ret;

	ret = al_mat4_empty();
	ret.m[0] = x;
	ret.m[5] = y;
	ret.m[10] = z;
	ret.m[15] = 1;

	return (ret);
}
