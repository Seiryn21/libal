#ifndef REGEX_H
#define REGEX_H

#include "libal.h"

typedef struct s_list t_list;

typedef struct	s_regstate
{
	int			id;
	int			type;
	union	
	{
		int flag;
		int limit[2];
		char *match;
	};
	t_list		*out;
	t_list		*link;
}				t_regstate;

typedef struct	s_regex
{
	int			nmatch;
	int 		statecount;
	t_regstate	*in;
	t_list 		*states;
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
int al_create_statefrag(t_regfrag *ret, t_regex *preg, char *match);


int al_regcomp(t_regex *preg, char *regex, int flags);

int al_regexec(t_regex *preg, char *string, size_t nmatch, t_regmatch *match, int flags);

void al_regfree(t_regex *preg);

#endif
