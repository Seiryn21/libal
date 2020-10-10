#include "json.h"

int al_json_addproperty(t_jsonobject *obj, char *name, t_jsonvalue value)
{
	t_list			*current;
	t_jsonproperty	*old_prop;
	t_jsonproperty	current_prop;
	
	current = NULL;
	if(obj != NULL)
	{
		old_prop = al_json_getproperty(*obj, name);
		if(old_prop)
		{
			al_json_freevalue(old_prop->value);
			old_prop->value = al_json_duplicatevalue(value);
			return (1);
		}
	}
	current_prop.name = al_strdup(name);
	current_prop.value = al_json_duplicatevalue(value);
	current = al_lstnew(&current_prop, sizeof(t_jsonproperty));
	if(current == NULL)
		return (0);
	al_lstadd(obj, current);
	return (1);
}

void al_json_freeproperty(void *content, size_t t)
{
	t_jsonproperty *property;

	(void)t;
	property = (t_jsonproperty*)content;
	al_json_freevalue(property->value);
	free(property->name);
	free(property);
}

void al_json_removeproperty(t_jsonobject *object, char *name)
{
	t_list			**current;
	t_jsonproperty	*current_prop;

	current = object;
	while(*current)
	{
		current_prop = (t_jsonproperty*)(*current)->content;
		if(al_strequ(current_prop->name, name))
		{
			al_lstdel_one(current, al_json_freeproperty);
			return ;
		}
		current = &((*current)->next);
	}

}

t_jsonproperty *al_json_getproperty(t_jsonobject object, char *name)
{
	t_list			*current;
	t_jsonproperty	*current_prop;

	current = object;
	while(current)
	{
		current_prop = (t_jsonproperty*)current->content;
		if(al_strequ(current_prop->name, name))
			return (current_prop);
		current = current->next;	
	}
	return (NULL);
}
