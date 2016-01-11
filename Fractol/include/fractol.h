/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:25:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/11 17:22:05 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# include <stdio.h> // TMPE

typedef struct	s_mouse
{
	int x;
	int y;
	int	button;
}				t_mouse;

typedef struct	s_img
{
	void	*adr;
	char	*img;
	int		endian;
	int		bpp;
	int		sl;
}				t_img;

typedef struct	s_arg
{
	char	*fract;
	int		w;
	int		h;
}				t_arg;

typedef struct	s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		kp;
	int		km;
}				t_key;

typedef struct	s_fract
{
	float	c_re;
	float	c_im;
	float	dw;
	float	dh;
	float	x;
	float	y;
	float	x2;
	float	y2;
	float	zoom;
	float	offx;
	float	offy;
	int		n;
	int		max;
}				t_fract;

typedef struct	s_env
{
	t_key	key;
	t_mouse	mouse;
	t_img	img;
	t_arg	arg;
	t_fract	f;
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
}				t_env;

/*
**	main.c functions
*/

void			ft_getargs(t_env *e, int argc, char **argv);
void			ft_dispargs(void);
void			ft_error(int err);

/*
**	core.c functions
*/

void			ft_core(t_env *e);
void			ft_displayfract(t_env *e);
void			ft_initenv(t_env *e);

/*
**	hook.c functions
*/

int				ft_expose_hook(t_env *e);
int				ft_loop_hook(t_env *e);
int				ft_key_pressed(int keycode, t_env *e);
int				ft_key_released(int keycode, t_env *e);
int				ft_mouse_pos(int x, int y, t_env *e);

/*
**	draw.c functions
*/

void			ft_imgpixelput(t_env *e, int x, int y, int color);
void			ft_initimg(t_env *e);
int				ft_getcolor(t_env *e, int iteration);

/*
**	fractale.c
*/

void			ft_julia(t_env *e, int x, int y);
void			ft_mandelbrot(t_env *e, int x, int y);
void			ft_initfract(t_env *e);

#endif