#include "print.h"

void al_putchar(char c)
{
	al_putchar_fd(c, 1);
}

void al_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
