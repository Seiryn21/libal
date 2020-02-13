#include "print.h"

static void al_putdec(float f, int prec, int fd)
{
	int digit;

	digit = (int)f * 10;
	al_putchar_fd('0' + digit, fd);
	if(prec > 0)
		al_putdec(f * 10 - digit, prec - 1, fd);
}

void	al_putfloat(float f, int prec)
{
	al_putfloat_fd(f, prec, 1);
}


void	al_putfloat_fd(float f, int prec, int fd)
{
	int int_part;

	int_part = (int)f;
	al_putnbr(int_part);
	al_putchar('.');
	f = f - int_part;
	if(f < 0)
		f = -f;
	al_putdec(f, prec, fd);
}


