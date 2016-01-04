/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:11:00 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/04 15:01:01 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_read(t_env *e, const char *argv)
{
	int		fd;
	char	*line;
	int		**tab;

	ft_error((fd = open(argv, O_RDONLY)));
	ft_error((int)(tab = (int**)malloc(sizeof(int*) * TAB_SIZE)));
	e->minh = 0;
	e->maxh = 0;
	get_next_line(fd, &line);
	e->gh = 0;
	e->gw = ft_wordcount(line, ' ');
	ft_tabassign(e, tab, line);
	e->gh++;
	while (get_next_line(fd, &line))
	{
		ft_tabassign(e, tab, line);
		free(line);
		e->gh++;
	}
	printf("gh: %d, gw: %d\n", e->gh, e->gw);
	close(fd);
	return (tab);
}

void	ft_getlinenum(t_env *e, const char *argv)
{
//	int		fd;
	char	*buf;

	if (argv)
		return ;
//	fd = open(argv, O_RDONLY);
	buf = ft_strnew(BUFFSIZE);
/*	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		e->gh += ret;
	}*/
	e->gh = 10;
	e->gw = 10;
//	close(fd);
}

void	ft_tabassign(t_env *e, int **tab, const char *line)
{
	int i;
	int x;

	i = 0;
	x = 0;
	ft_error((int)(tab[e->gh] = (int*)malloc(sizeof(int) * e->gw)));
	while (x < e->gw)
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			tab[e->gh][x] = ft_atoi(&line[i]);
			e->minh = (tab[e->gh][x] < e->minh ? tab[e->gh][x] : e->minh);
			e->maxh = (tab[e->gh][x] > e->maxh ? tab[e->gh][x] : e->maxh);
			while (line[i] != ' ')
				i++;
			x++;
		}
		i++;
	}
}

void	ft_maperror(const char *line)
{
	int			n;
	static int	t = 0;

	n = 0;
	while (line[n] != '\0')
	{
		ft_error((ft_isdigit(line[n]) || line[n] == ' ' || line[n] == '-'));
		ft_error(!(line[n + 1] != 0 && line[n] == '-' && line[n + 1] == '0'));
		n++;
	}
	ft_error(!(t != 0 && n != t));
	t = n;
}

void	ft_error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr_fd("error\n", 2);
		exit(0);
	}
}
