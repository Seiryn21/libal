#include "regex.h"
#include "stdio.h"

static int al_isquantifier(char c)
{
	return (c == '+' || c == '*' || c == '?'  || c == '{');
}

static int al_comp_match(t_regfrag *ret, t_regex *preg, char **regex)
{
	char *match;

	match = al_strnew(1);
	match[0] = **regex;
	al_create_matchfrag(ret, preg, match);
	(*regex)++;
	return (0);
}

static int al_comp_quantifier(t_regstate ***out, t_regex *preg, t_regfrag frag, char **regex)
{
	t_regstate *quantifier;

	if(al_isquantifier(**regex))
	{
		if(**regex == '?')
			quantifier = al_create_quantifierstate(preg, 0, 1);
		if(**regex == '*')
			quantifier = al_create_quantifierstate(preg, 0, -1);
		if(**regex == '+')
			quantifier = al_create_quantifierstate(preg, 1, -1);
		(*regex)++;
		if(**regex == '?')
		{
			(*regex)++;
			quantifier->limit[0] = 1;
		}
		quantifier->out[0] = frag.in;
		**out = quantifier;
		*(frag.out->out) = quantifier;
		*out = &(quantifier->out[1]);
	}
	else
	{
		**out = frag.in;
		*out = frag.out->out;
	}
	return (0);	
}


static int al_comp_group(t_regfrag *ret,t_regex *preg, char **regex)
{	
	t_regfrag	frag;
	t_regstate	**out;
	t_list		*fork;

	al_create_groupfrag(ret, preg);
	fork = al_lstnew_ptr(NULL);
	out = (t_regstate**)(&(fork->content));
	while(**regex != '\0' && **regex != ')')
	{
		if(**regex == '(')
		{
			(*regex)++;
			al_comp_group(&frag, preg, regex);
		}
		else if(al_isquantifier(**regex))
			al_putline("error");
		else if(**regex != '|')
			al_comp_match(&frag, preg, regex);
		al_comp_quantifier(&out, preg, frag, regex);
		if(**regex == '|')
		{
			*out = ret->out;
			al_lstadd(&fork, al_lstnew_ptr(NULL));
			out = (t_regstate**)(&(fork->content));
			(*regex)++;	
		}	
	}
	*out = ret->out;
	ret->in->out = (t_regstate**)(al_lsttoarray(fork));
	al_lstdel(&fork, NULL);
	(*regex)++;
	return (ret->in->flag && **regex);		
}

int al_regcomp(t_regex *preg, char *regex, int flags)
{
	t_regfrag frag;
	t_regstate **tab;

	(void)flags;
	preg->statecount = 0;
	preg->nmatch = 0;
	preg->states.lst = NULL;
	al_comp_group(&frag, preg, &regex);
	preg->in = frag.in;
	tab = (t_regstate**)al_lsttoarray(preg->states.lst);
	al_lstdel(&(preg->states.lst), NULL);
	preg->states.tab = tab;
	return (0);
}

