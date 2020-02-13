#include "math.h"

void al_mat4_print(t_mat4 a)
{
	int i;
	int j;

	i = 0; 
	while(i < 4)
	{
		j = 4;
		while(j < 4)
		{
			if(a.m[j + i * 4] >= 0)
				al_putchar(' ');
			al_putfloat(a.m[j + i * 4], 4);
			al_putchar(' ');
			j++;
		}
		al_putchar('\n');
	}
}
