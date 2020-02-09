#include "print.h"

void al_putline(char *str)
{
	al_putline_fd(str, 1);
}

void al_putline_fd(char *str, int fd)
{
	al_putstr_fd(str, fd);
	al_putchar_fd('\n', fd);
}
