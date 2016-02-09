/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:26:43 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 18:36:23 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>

# define ABS(x) (x < 0 ? -x : x)
# define PI 3.1415926
# define DEG2RAD PI / 180
# define RAD2DEG 180 / PI

enum { X, Y, Z };

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct	s_vec3i
{
	int		x;
	int		y;
	int		z;
}				t_vec3i;

typedef struct	s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct	s_vec2i
{
	int		x;
	int		y;
}				t_vec2i;

/*
**	vec.c functions
*/

t_vec3			vec3_up(void);
t_vec3			vec3_right(void);
t_vec3			vec3_forward(void);
t_vec3			vec3_fmul(t_vec3 vec3, double m);
t_vec2			vec2_fmul(t_vec2 vec2, double m);

/*
**	vec2_a.c functions
*/

t_vec2			vec2(double x, double y);
t_vec2i			vec2i(t_vec2 vec2);
t_vec2			vec2_scale(t_vec2 vec2a, double scale);
double			vec2_magnitude(t_vec2 vec2);
void			vec2_normalize(t_vec2 *vec2);

/*
**	vec2_b.c functions
*/

t_vec2			vec2_add(t_vec2 vec2a, t_vec2 vec2b);
t_vec2			vec2_sub(t_vec2 vec2a, t_vec2 vec2b);
t_vec2			vec2_mul(t_vec2 vec2a, t_vec2 vec2b);
double			vec2_dot(t_vec2 vec2a, t_vec2 vec2b);
void			vec2_rot(t_vec2 *vec2, double theta);

/*
**	vec3_a.c functions
*/

t_vec3			vec3(double x, double y, double z);
t_vec3i			vec3i(t_vec3 vec3);
t_vec3			vec3_scale(t_vec3 vec3a, double scale);
double			vec3_magnitude(t_vec3 vec3);
void			vec3_normalize(t_vec3 *vec3);

/*
**	vec3_b.c functions
*/

t_vec3			vec3_add(t_vec3 vec3a, t_vec3 vec3b);
t_vec3			vec3_sub(t_vec3 vec3a, t_vec3 vec3b);
t_vec3			vec3_mul(t_vec3 vec3a, t_vec3 vec3b);
double			vec3_dot(t_vec3 vec3a, t_vec3 vec3b);
void			vec3_rot(t_vec3 *vec3, int axis, double theta);

/*
**	vec3_c.c
*/

void			vec3_clamp(t_vec3 *vec3, double min, double max);

#endif
