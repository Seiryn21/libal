#include "str.h"

static void	al_split(char **ret, char *current, char *next, int *count)
{
	if(next - current > 1)
	{
		ret[*count] = al_strnew(next - current);
		if(ret[*count] != NULL)
			al_strncpy(ret[*count], current, next - current);
		(*count)++;
	}
}

char 		**al_strsplit(const char *str, char c)
{
	int		count;
	char	*next;
	char	*current;
	char 	**ret;

	if(str == NULL)
		return (NULL);
	count = al_strcnt(str, c);
	ret = al_memalloc(sizeof(char*) * (count + 1));
	if(ret == NULL)
		return (NULL);
	count = 0;
	current = (char*)str;
	next = al_strchr(current, c);
	while(next != NULL)
	{
		al_split(ret, current, next, &count);
		current = next + 1;
		next = al_strchr(current, c);
	}
	al_split(ret, current, current + al_strlen(current), &count);
	return (ret);
}
