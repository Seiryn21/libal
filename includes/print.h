#ifndef PRINT_H
#define PRINT_H

#include "libal.h"

void al_putnbr(int nbr);
void al_putstr(char *str);
void al_putchar(char c);
void al_putline(char *str);

void al_putnbr_fd(int nbr, int fd);
void al_putstr_fd(char *str, int fd);
void al_putchar_fd(char c, int fd);
void al_putline_fd(char *str, int fd);

#endif
