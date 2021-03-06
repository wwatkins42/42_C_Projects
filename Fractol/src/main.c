/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:28:40 by wwatkins          #+#    #+#             */
/*   Updated: 2017/04/15 18:28:08 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_env	e;

	ft_getargs(&e, argc, argv);
	ft_core(&e);
	return (0);
}

void 	ft_getargs(t_env *e, int argc, char **argv)
{
	int i;

	i = 0;
	ft_error((argc >= 1 && argc <= 6));
	argc == 1 ? ft_dispargs() : 0;
	e->arg.fract = ft_strdup(argv[1]);
	if (ft_strcmp(e->arg.fract, "julia") && ft_strcmp(e->arg.fract,
		"mandelbrot") && ft_strcmp(e->arg.fract, "burningship") &&
		ft_strcmp(e->arg.fract, "tricorn"))
		ft_dispargs();
	e->arg.w = 0;
	e->arg.h = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-w") && i + 1 < argc)
			e->arg.w = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-h") && i + 1 < argc)
			e->arg.h = ft_atoi(argv[i + 1]);
	}
	!ft_strcmp(e->arg.fract, "mandelbrot") ? e->f.n = 0 : 0;
	!ft_strcmp(e->arg.fract, "julia") ? e->f.n = 1 : 0;
	!ft_strcmp(e->arg.fract, "burningship") ? e->f.n = 2 : 0;
	!ft_strcmp(e->arg.fract, "tricorn") ? e->f.n = 3 : 0;
	e->arg.w = (e->arg.w < 300 || e->arg.w > 2560 ? 800 : e->arg.w);
	e->arg.h = (e->arg.h < 300 || e->arg.h > 1440 ? 800 : e->arg.h);
}

void	ft_dispargs(void)
{
	ft_putendl("\nusage: ./fractol (type) [-w width] [-h height]");
	ft_putendl(" type: julia\n       mandelbrot\n       burningship");
	ft_putendl("       tricorn\n");
	ft_putendl(" keys: 'p' to switch colors");
	ft_putendl("       'o' to switch from black or max iteration color");
	ft_putendl("       zoom with '+', '-' or 'mousewheel'");
	ft_putendl("       move around with 'mouse' (while zooming)");
	ft_putendl("       'pgup' and 'pgdown' to modify max iteration");
	ft_putendl("       in julia 'mouse' will also change fractal settings");
	exit(0);
}

void	ft_error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr_fd("error\n", 2);
		exit(0);
	}
}
