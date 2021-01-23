#ifndef STR_H
#define STR_H

#include "libal.h"

int		al_strcnt(const char *str, char c);
int		al_strequ(const char *s1, const char *s2);
int		al_strcmp(const char *s1, const char *s2);
int		al_strnequ(const char *s1, const char *s2, size_t n);
int		al_strncmp(const char *s1, const char *s2, size_t n);

void	al_strdel(char *str);

char	*al_strnew(size_t size);
char	*al_strtolower(char *str);
char	*al_strtoupper(char *str);
char	*al_strdup(const char *src);
char	*al_strchr(const char *src, char c);
char	*al_strrchr(const char *src, char c);
char	*al_strndup(const char *src, size_t n);
char	*al_strcpy(char *dest, const char *src);
char	*al_strcat(char *dest, const char *src);
char	*al_strncpy(char *dest, const char *src, size_t n);
char	*al_strncat(char *dest, const char *src, size_t n);
char	*al_strjoin(char *s1, char *s2);
char	*al_strnjoin(char *s1, char *s2, size_t n);
char	*al_strmap(char *str, char (*f)(char));

char 	**al_strsplit(const char *str, char c);

size_t 	al_strlen(const char *src);

#endif
