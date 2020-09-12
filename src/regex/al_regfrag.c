#include "libal.h"

static t_regstate *al_create_regstate(t_regex *preg, int type)
{
	t_regstate 	new;
	t_list		*new_lst;
	t_list		*new_lst_ptr;

	new.type = type;
	new.out = NULL;
	new.id = preg->statecount;
	new_lst = al_lstnew(&new, sizeof(t_regstate));
	new_lst_ptr = al_lstnew_ptr(new_lst->content);
	al_lstadd(&(preg->states), new_lst);
	((t_regstate*)(new_lst->content))->link = new_lst_ptr; 
	preg->statecount++;
	return (new_lst->content);
}

void al_concat_regfrag(t_regfrag *dest, t_regfrag src)
{
	al_lsteadd(&(dest->out->out), src.in->link);
	dest->out = src.out;
}

int al_create_statefrag(t_regfrag *ret, t_regex *preg, char *match)
{
	t_regstate	*new;

	new = al_create_regstate(preg, 0); 
	new->match = match;
	ret->in = new;
	ret->out = new;
	return (0);
}

int al_create_groupfrag(t_regfrag *ret, t_regex *preg)
{
	t_regstate *in;
	t_regstate *out;

	in = al_create_regstate(preg, 1);
	out = al_create_regstate(preg, 1);
	in->flag = preg->nmatch * 2;
	out->flag = preg->nmatch * 2 + 1;
	preg->nmatch++;
	ret->in = in;
	ret->out = out;
	return (0);
}
