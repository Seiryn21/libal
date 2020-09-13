#include "libal.h"

static t_regstate *al_create_regstate(t_regex *preg, int type)
{
	t_regstate 	*new;

	new = &(preg->states[preg->statecount]);
	new->type = type;
	new->out = NULL;
	new->id = preg->statecount;
	preg->statecount++;
	return (new);
}

int al_create_groupfrag(t_regfrag *ret, t_regex *preg)
{
	t_regstate *in;
	t_regstate *out;

	in = al_create_regstate(preg, 1);
	in->flag = preg->nmatch * 2;
	out = al_create_regstate(preg, 1);
	out->flag = preg->nmatch * 2 + 1;
	out->out = al_memalloc(2 * sizeof(t_regstate*));
	preg->nmatch++;
	ret->in = in;
	ret->out = out;
	return (0);
}

int al_create_matchfrag(t_regfrag *ret, t_regex *preg, char *match)
{
	t_regstate	*new;

	new = al_create_regstate(preg, 0); 
	new->match = match;
	new->out = al_memalloc(2 * sizeof(t_regstate*));
	ret->in = new;
	ret->out = new;
	return (0);
}

t_regstate *al_create_quantifierstate(t_regex *preg, int min, int max)
{
	t_regstate *new;
	
	new = al_create_regstate(preg, 2);
	new->limit[0] = 0;
	new->limit[1] = min;
	new->limit[2] = max;
	new->out = al_memalloc(3 * sizeof(t_regstate*));
	return (new);
}
