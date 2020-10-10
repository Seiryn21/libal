#include "json.h"

char *al_json_objecttostr(t_jsonobject object)
{
	int len;
	int pos;
	int cur;
	char *ret;
	char **properties;

	cur = 0;
	pos = 0;
	len = 1;
	properties = al_memalloc(sizeof(char*) * (al_lstlen(object) + 1));
	while(object)
	{
		properties[pos] = al_json_propertytostr(*(t_jsonproperty*)(object->content));
		len += al_strlen(properties[pos]) + 1;
		pos++;
		object = object->next;
	}
	ret = al_strnew(len);
	pos = 0;
	ret[0] = '{';
	while(properties[cur])
	{
		pos++;
		al_strcpy(ret + pos, properties[cur]);
		pos += al_strlen(properties[cur]);
		free(properties[cur]);
		cur++;
		ret[pos] = ',';
	}
	free(properties);
	ret[pos] = '}';
	return ret;
}

char *al_json_valuetostr(t_jsonvalue value)
{
	int len;
	char *ret;

	if(value.type == JSON_BOOL)
		ret = al_strdup(value.boolean ? "true" : "false");
	else if(value.type == JSON_NOTHING)
		ret = al_strdup("null");
	else if(value.type == JSON_STRING)
	{
		len = al_strlen(value.string);
		ret = al_strnew(len + 3);
		ret[0] = '\"';
		al_strcpy(ret + 1, value.string);
		ret[len + 1] = '\"';
	}
	else if(value.type == JSON_OBJECT)
		ret = al_json_objecttostr(value.object);
	else
		ret = al_strdup("tmp");
	return ret;
}


char *al_json_propertytostr(t_jsonproperty property)
{
	int name_len;
	int value_len;
	char *ret;
	char *value;
	
	value = al_json_valuetostr(property.value);
	name_len = al_strlen(property.name);
	value_len = al_strlen(value);
	ret = al_strnew(3 + name_len + value_len);
	ret[0] = '\"';
	al_strcpy(ret + 1, property.name);
	ret[name_len + 1] = '\"';
	ret[name_len + 2] = ':';
	al_strcpy(ret + name_len + 3, value);
	free(value);
	return (ret);
}


