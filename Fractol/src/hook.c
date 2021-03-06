/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:03:22 by wwatkins          #+#    #+#             */
/*   Updated: 2017/04/25 14:18:20 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_loop_hook(t_env *e)
{
	if (e->key.kp || e->key.km || e->mouse.zp || e->mouse.zm)
	{
		e->f.zoom *= 1.0f + (e->key.kp * 0.05f - e->key.km * 0.05f);
		e->f.zoom < 0.01f ? e->f.zoom = 0.01f : 0;
		e->f.offx += ((double)e->mouse.x - e->hwin_w) / (e->hwin_w * e->f.zoom) / 10.0;
		e->f.offy += ((double)e->mouse.y - e->hwin_h) / (e->hwin_h * e->f.zoom) / 10.0;
	}
	if (e->f.n == 1)
	{
		e->f.c_re = (double)(e->mouse.x - e->hwin_w) / 300.0f;
		e->f.c_im = (double)(e->mouse.y - e->hwin_w) / 300.0f;
	}
	if (e->key.p == 1)
		e->f.color = e->f.color < 7 ? e->f.color + 1 : 0;
	e->key.pu || e->key.pd ? e->f.max += (e->key.pu - e->key.pd) : 0;
	e->f.max < 1 ? e->f.max = 1 : 0;
	ft_expose_hook(e);
	return (0);
}

int		ft_expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->key.kp || e->key.km || e->mouse.zp || e->mouse.zm || e->key.p ||
		e->key.pu || e->key.pd)
		ft_displayfract(e);
	e->f.n == 1 ? ft_displayfract(e) : 0;
	e->mouse.zp = 0;
	e->mouse.zm = 0;
	e->key.p = 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	ft_debugtext(e);
	return (0);
}

void	ft_debugtext(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, 2, 0xFFFFDF, ft_itoa(e->f.max));
}

int		ft_key_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 31 && e->key.o == 0 ? keycode = -1 : 0;
	keycode == -1 && e->key.o == 0 ? e->key.o = 1 : 0;
	keycode == 31 && e->key.o == 1 ? e->key.o = 0 : 0;
	keycode == -1 || keycode == 31 ? ft_displayfract(e) : 0;
	keycode == 35 ? e->key.p = 1 : 0;
	keycode == 69 ? e->key.kp = 1 : 0;
	keycode == 78 ? e->key.km = 1 : 0;
	keycode == 116 ? e->key.pu = 1 : 0;
	keycode == 121 ? e->key.pd = 1 : 0;
	return (0);
}

int		ft_key_released(int keycode, t_env *e)
{
	keycode == 35 ? e->key.p = 0 : 0;
	keycode == 69 ? e->key.kp = 0 : 0;
	keycode == 78 ? e->key.km = 0 : 0;
	keycode == 116 ? e->key.pu = 0 : 0;
	keycode == 121 ? e->key.pd = 0 : 0;
	return (0);
}
