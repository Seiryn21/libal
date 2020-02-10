#include "math.h"

float al_sqrt(float number)
{
	float	a;
	float	b;
	float	dif;
	float	new;

	a = 0;
	b = number / 2.;
	dif = -1;
	new = -1;
	while(new != - 1 && al_abs(dif) > SQRT_PRECISION)
	{
		new = (a + b) / 2.;
		dif = number - new * new;
		if(dif > 0)
			a = new;
		else
			b = new;
	}
	return new;
}
