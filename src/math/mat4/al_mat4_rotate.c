#include "math.h"

t_mat4			al_mat4_rotatex(float theta)
{
	t_mat4 ret;

	ret = al_mat4_identity();
	ret.m[5] = al_cos(theta);
	ret.m[6] = -al_sin(theta);
	ret.m[9] = al_sin(theta);
	ret.m[10] = al_cos(theta);
	return (ret);
}

t_mat4			al_mat4_rotatey(float theta)
{
	t_mat4 ret;

	ret = al_mat4_identity();
	ret.m[0] = al_cos(theta);
	ret.m[2] = al_sin(theta);
	ret.m[8] = -al_sin(theta);
	ret.m[10] = al_cos(theta);
	return (ret);
}

t_mat4			al_mat4_rotatez(float theta)
{
	t_mat4 ret;

	ret = al_mat4_identity();
	ret.m[0] = al_cos(theta);
	ret.m[1] = -al_sin(theta);
	ret.m[4] = al_sin(theta);
	ret.m[5] = al_cos(theta);
	return (ret);
}
