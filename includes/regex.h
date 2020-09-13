#ifndef REGEX_H
#define REGEX_H

#include "libal.h"

typedef struct s_list t_list;
typedef struct s_regstate t_regstate;

struct			s_regstate
{
	int			id;
	int			type;
	union	
	{
		int 	flag;
		int 	limit[3];
		char	 *match;
	};
	t_regstate	**out;
};

typedef struct	s_regex
{
	int			nmatch;
	int 		statecount;
	t_regstate	*in;
	t_regstate	*states;
}				t_regex;

typedef struct	s_regmatch
{
	int 		begin;
	int 		end;
}				t_regmatch;

typedef struct	s_regfrag
{
	t_regstate	*in;
	t_regstate	*out;	
}				t_regfrag;

void al_concat_regfrag(t_regfrag *dest, t_regfrag src);

int al_create_groupfrag(t_regfrag *ret, t_regex *preg);
int al_create_matchfrag(t_regfrag *ret, t_regex *preg, char *match);

t_regstate *al_create_quantifierstate(t_regex *preg, int min, int max);


int al_regcomp(t_regex *preg, char *regex, int flags);

int al_regexec(t_regex *preg, char *string, size_t nmatch, t_regmatch *match, int flags);

void al_regfree(t_regex *preg);

#endif
