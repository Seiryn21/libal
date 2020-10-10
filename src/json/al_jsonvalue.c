#include "json.h"

void		al_json_freevalue(t_jsonvalue value)
{
	if(value.type == JSON_STRING)
		free(value.string);
//	else if(value.type == JSON_ARRAY)
//		al_json_freearray(value.array);
	else if(value.type == JSON_OBJECT)
		al_json_freeobject(value.object);
}

t_jsonvalue	al_json_initvalue(t_jsontype type, ...)
{
	t_jsonvalue new;
	va_list		ap;
	
	va_start(ap, type);
	new.type = type;
	if(type == JSON_BOOL)
		new.boolean = va_arg(ap, int);
	else if(type == JSON_STRING)
		new.string = va_arg(ap, char*);
	else if(type == JSON_NUMBER)
		new.number = va_arg(ap, double);
	else if(type == JSON_ARRAY)
		new.array = va_arg(ap, t_jsonarray);
	else if(type == JSON_OBJECT)
		new.object= va_arg(ap, t_jsonobject); 
	va_end(ap);
	return (new);
}

t_jsonvalue al_json_duplicatevalue(t_jsonvalue value)
{
	t_jsonvalue new;
	
	new = value;
	if(new.type == JSON_STRING)
		new.string = al_strdup(new.string);
//	else if(new.type == JSON_ARRAY)
//		new.array = al_json_duplicatearray(new.array);
	else if(new.type == JSON_OBJECT)
		new.object = al_json_duplicateobject(new.object);
	return  (new);
}
