/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:03:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/11 15:45:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_loop_hook(t_env *e)
{
	e->f.zoom *= 1.0f + ((double)e->key.kp * 0.1f - (double)e->key.km * 0.1f);
	e->f.zoom < 0.0f ? e->f.zoom = 0.0f : 0;

	e->key.a || e->key.d ? e->f.dw += (double)(e->key.a - e->key.d) * 6.0f : 0;
	e->key.w || e->key.s ? e->f.dh += (double)(e->key.w - e->key.s) * 6.0f : 0;
	if (e->key.kp || e->key.km)
	{
		e->f.dw += ((double)e->win_w / 2.0f) - e->mouse.x;
		e->f.dh += ((double)e->win_h / 2.0f) - e->mouse.y;
	}
	ft_expose_hook(e);
	return (0);
}

int		ft_expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->key.w || e->key.s || e->key.a || e->key.d || e->key.kp || e->key.km)
		ft_displayfract(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	return (0);
}

int		ft_key_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 126 ? e->key.w = 1 : 0;
	keycode == 125 ? e->key.s = 1 : 0;
	keycode == 123 ? e->key.a = 1 : 0;
	keycode == 124 ? e->key.d = 1 : 0;
	keycode == 69 ? e->key.kp = 1 : 0;
	keycode == 78 ? e->key.km = 1 : 0;
	return (0);
}

int		ft_key_released(int keycode, t_env *e)
{
	keycode == 126 ? e->key.w = 0 : 0;
	keycode == 125 ? e->key.s = 0 : 0;
	keycode == 123 ? e->key.a = 0 : 0;
	keycode == 124 ? e->key.d = 0 : 0;
	keycode == 69 ? e->key.kp = 0 : 0;
	keycode == 78 ? e->key.km = 0 : 0;
	return (0);
}

int		ft_mouse_pos(int x, int y, t_env *e)
{
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}
