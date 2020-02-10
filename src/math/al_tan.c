#include "math.h"

float al_tan(float theta)
{
	float sin;
	float cos;

	sin = al_sin(theta);
	cos = al_cos(theta);
	return (sin / cos);
}
