#include "math.h"

t_mat4 al_mat4_projection(float near, float far, float fov, float aspect)
{
	t_mat4 ret;
	float diff;
	float tan_fov;

	ret = al_mat4_empty();
	diff = far - near;
	tan_fov = al_tan(fov / 2.);
	ret.m[0] = 1. / (aspect * tan_fov);
	ret.m[5] = 1. / tan_fov;
	ret.m[10] = - (far + near) / diff;
	ret.m[11] = - (2 * far * near) / diff;
	ret.m[14] = -1;
	return (ret);
}
