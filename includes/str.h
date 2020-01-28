#ifndef STR_H
#define STR_H

#include "libal.h"

char	*al_strnew(size_t size);
char	*al_strdup(const char *src);
char	*al_strcpy(char *dest, const char *src);
char	*al_strcat(char *dest, const char *src);
char	*al_strncpy(char *dest, const char *src, size_t n);
char	*al_strncpy(char *dest, const char *src, size_t n);


size_t 	al_strlen(const char *src);

#endif
