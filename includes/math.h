#ifndef MATH_H
#define MATH_H

#include "libal.h"

#define	QUARTER_PI		0.78539816
#define HALF_PI			1.57079632
#define PI 				3.14159265
#define TWO_PI			6.28318530
#define SQRT_PRECISION 	0.000001

typedef struct	s_vec3
{
	float		v[3];
}				t_vec3;

typedef struct	s_vec4
{
	float		v[4];
}				t_vec4;

typedef struct	s_mat4
{
	float		m[16];
}				t_mat4;


float 			al_abs(float number);
float			al_cos(float theta);
float			al_sin(float theta);
float			al_tan(float theta);
float			al_sqrt(float number);
float			al_pow(float number, int n);

float			al_vec3_len(t_vec3 a);
float			al_vec3_dotproduct(t_vec3 a, t_vec3 b);

t_vec3			al_vec3_init(float x, float y,  float z);
t_vec3			al_vec3_norm(t_vec3 a);
t_vec3			al_vec3_div(t_vec3 a, float n);
t_vec3			al_vec3_mult(t_vec3 a, float n);
t_vec3			al_vec3_add(t_vec3 a, t_vec3 b);
t_vec3			al_vec3_sub(t_vec3 a, t_vec3 b);
t_vec3 			al_vec3_crossproduct(t_vec3 a, t_vec3 b);

t_vec4			al_vec4_from_vec3(t_vec3 a);

t_mat4			al_mat4_empty();
t_mat4			al_mat4_identity();
t_mat4			al_mat4_mult(t_mat4 a, t_mat4 b);
t_mat4			al_mat4_rotatex(float theta);
t_mat4			al_mat4_rotatey(float theta);
t_mat4			al_mat4_rotatez(float theta);
t_mat4			al_mat4_scale(t_vec3 scale);
t_mat4			al_mat4_translate(t_vec3 pos);
t_mat4			al_mat4_lookat(t_vec3 from, t_vec3 to);
t_mat4 			al_mat4_projection(float near, float far, float fov, float aspect);

t_vec4			al_mat4_mult_vec4(t_mat4 mat, t_vec4 vec);


#endif
