/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:28:05 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/03 17:05:53 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# include <math.h>
# include <stdio.h> // TEMPORARY

# define TAB_SIZE 4096 // UGLY AS FUCK
# define SQRT3 1.73205
# define SQRT2 1.41421
# define PI 3.14159
# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_point
{
	int x;
	int y;
	int h;
}				t_point;

typedef struct	s_key
{
	int	w;
	int	s;
	int a;
	int d;
}				t_key;

typedef struct	s_cam
{
	t_point	move;
	t_point	rota;
	int		x;
	int		y;
	int		speed;
	float	zoom;
}				t_cam;

typedef struct	s_env
{
	t_point		**pts;
	t_key		key;
	t_cam		cam;
	void		*mlx;
	void		*win;
	int			gw;
	int			gh;
	int			scw;
	int			sch;
	int			minh;
	int			maxh;
	float		ir;
	int			color;
}				t_env;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

int				**ft_read(t_env *e, const char *argv);
void			ft_tabassign(t_env *e, int **tab, const char *line);
void			ft_maperror(const char *line);
void			ft_error(int err);

void			ft_core(t_env *e, int **tab);
void			ft_assigncoor(t_env *e, int **tab);
void			ft_displaylines(t_env *e);
void			ft_drawline(t_env e, t_point p, t_point p1, int color);
int				ft_color(t_point p, t_point p1, int color);
int				ft_getalt(t_point p, t_point p1);
t_point			ft_point(int x, int y);

/*
**	Mlx hook functions.
*/

int				ft_keyhook_pressed(int keycode, t_env *e);
int				ft_keyhook_release(int keycode, t_env *e);
int				ft_loophook(t_env *e);
int				ft_exposehook(t_env *e);
int				ft_debugmessage(t_env *e);

#endif
