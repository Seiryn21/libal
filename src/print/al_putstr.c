#include "print.h"

void al_putstr(char *str)
{
	al_putstr_fd(str, 1);
}

void al_putstr_fd(char *str, int fd)
{
	write(fd, str, al_strlen(str));
}
