#include "print.h"

void al_putnbr(int nbr)
{
	al_putnbr_fd(nbr, 1);
}

void al_putnbr_fd(int nbr, int fd)
{
	char c;

	c = '0' + (nbr % 10);
	if(nbr > 9)
		al_putnbr_fd(nbr / 10, fd);
	write(fd, &c, 1);
}
