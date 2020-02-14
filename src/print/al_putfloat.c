#include "print.h"

void	al_putfloat(float f, int prec)
{
	al_putfloat_fd(f, prec, 1);
}


void	al_putfloat_fd(float f, int prec, int fd)
{
	int i;
	int int_part;

	if(f < 0)
	{
		al_putchar_fd('-', fd);
		f = -f;
	}
	int_part = (int)f;
	al_putnbr_fd(int_part, fd);
	al_putchar_fd('.', fd);
	i = 0;
	while(i < prec)
	{
		f = (f - int_part) * 10;
		int_part = (int)f;
		al_putchar_fd('0' + int_part, fd);
		i++;
	}
}


