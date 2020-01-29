#ifndef LST_H
#define LST_H

#include "libal.h"

typedef struct 		s_list
{

	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int		al_lstlen(t_list *begin);

t_list	*al_lstnew(void *const content, size_t content_size);

t_list	*al_lstget(t_list *begin, size_t n);
t_list	*al_lstlast(t_list *begin);

void	al_lstadd(t_list **begin, t_list *new);
void	al_lsteadd(t_list **begin, t_list *new);
void	al_lstnadd(t_list **begin, t_list *new, size_t n);

void	al_lstsort(t_list **begin, int(*cmp)(void *, size_t));

void	al_lstdel(t_list **begin, void (*del)(void *, size_t));
void	al_lstdel_one(t_list **begin, void (*del)(void *, size_t));

void	al_lstiter(t_list *begin, void (*iter)(void *, size_t));

#endif
