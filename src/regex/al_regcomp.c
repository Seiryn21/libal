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
	al_create_statefrag(ret, preg, match);
	(*regex)++;
	return (0);
}

/*
static int al_comp_quantifier(t_list **out, t_regfrag frag, char **regex)
{
	return (0);	
}
*/

static int al_comp_group(t_regfrag *ret,t_regex *preg, char **regex)
{	
	t_regfrag	frag;
	t_regfrag	current;

	al_create_groupfrag(ret, preg);
	current.out = ret->in;
	while(**regex != '\0' && **regex != ')')
	{
		if(**regex == '(')
		{
			(*regex)++;
			al_comp_group(&frag, preg, regex);
			(*regex)++;
		}
		else if(al_isquantifier(**regex))
			al_putline("error");
		else if(**regex != '|')
			al_comp_match(&frag, preg, regex);
//		if(al_isquantifier(**regex))
//			al_handle_quantifier();
//		else
			al_concat_regfrag(&current, frag);			
		if(**regex == '|')
		{
			al_lsteadd(&(current.out->out), ret->out->link);
			current.out = ret->in;
			(*regex)++;
		}
	}
	al_lsteadd(&(current.out->out), ret->out->link);
	return (ret->in->flag && **regex);		
}

int al_regcomp(t_regex *preg, char *regex, int flags)
{
	t_regfrag frag;

	(void)flags;
	preg->statecount = 0;
	preg->nmatch = 0;
	preg->states = NULL;
	al_comp_group(&frag, preg, &regex);
	preg->in = frag.in;
	return (0);
}

