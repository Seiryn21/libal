#include "json.h"

void al_json_freeobject(t_jsonobject object)
{
	al_lstdel(&object, al_json_freeproperty);
}

t_jsonobject al_json_duplicateobject(t_jsonobject object)
{
	t_jsonobject new;
	t_jsonproperty *old;
	t_jsonproperty current;

	new = NULL;
	while(object)
	{
		old = (t_jsonproperty*)(object->content);
		current.name = al_strdup(old->name);
		current.value = al_json_duplicatevalue(old->value);
		al_lstadd(&new, al_lstnew(&current, sizeof(t_jsonproperty)));
		object = object->next;
	}
	return new;
}
