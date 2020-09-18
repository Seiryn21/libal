#ifndef JSON_H
#define JSON_H

#include "libal.h"

typedef struct s_list t_list;
typedef t_list* t_jsonarray;
typedef t_list* t_jsonobject;

typedef enum			e_jsontype
{
						JSON_BOOL,
						JSON_STRING,
						JSON_NUMBER,
						JSON_ARRAY,
						JSON_OBJECT,
						JSON_NOTHING,
}						t_jsontype;

typedef struct			s_jsonvalue
{
	t_jsontype			type;
	union
	{
		int				boolean;
		char			*string;
		float			number;
		t_jsonarray		array;
		t_jsonobject	object;
	};
}						t_jsonvalue;

typedef	struct			s_jsonproperty
{
	char				*name;
	t_jsonvalue			value;
}						t_jsonproperty;

int				al_json_arraylen(t_jsonarray array);
void			al_json_freearray(t_jsonarray array);
t_jsonarray		al_json_duplicatearray(t_jsonarray array);

void			al_json_setelem(t_jsonarray *array, t_jsonvalue, int pos);
void			al_json_pushelem(t_jsonarray *array, t_jsonvalue);
void			al_json_insertelem(t_jsonarray *array, t_jsonvalue, int pos);
void			al_json_removeelem(t_jsonarray *array, int pos);
void			al_json_freeelem(void *elem, size_t t);
t_jsonvalue		*al_json_popelem(t_jsonarray *array);
t_jsonvalue		*al_json_getelem(t_jsonarray array, int pos);

int				al_json_addproperty(t_jsonobject *obj, char *name, t_jsonvalue val);
void			al_json_removeproperty(t_jsonobject *object, char *name);
void			al_json_freeproperty(void *property, size_t t);
t_jsonproperty	*al_json_getproperty(t_jsonobject object, char *name);

void			al_json_freeobject(t_jsonobject object);
t_jsonobject	al_json_duplicateobject(t_jsonobject object);

void			al_json_freevalue(t_jsonvalue value);
t_jsonvalue		al_json_initvalue(t_jsontype type, ...);
t_jsonvalue		al_json_duplicatevalue(t_jsonvalue value);

#endif
