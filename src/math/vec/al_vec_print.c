#include "math.h"

void	al_vec3_print(t_vec3 a)
{
	int i;

	i = 0;
	while(i < 3)
	{
		al_putfloat(a.v[i], 2);
		al_putchar(' ');
		i++;
	}
	al_putchar('\n');
}


void	al_vec4_print(t_vec4 a)
{
	int i;

	i = 0;
	while(i < 4)
	{
		al_putfloat(a.v[i], 2);
		al_putchar(' ');
		i++;
	}
}
