#include "regex.h"

void al_regfree(t_regex *preg)
{
	int i;
	t_regstate state;

	i = 0;
	while(i < preg->statecount)
	{
		state = preg->states[i];
		if(state.type == 0)
			free(state.match);
		free(state.out);
		i++;
	}
	free(preg->states);
}
