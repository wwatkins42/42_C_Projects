/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:01:22 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/14 11:00:09 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_env *e)
{
	int		fd;
	char	*line;
	t_obj	*obj;
	t_lgt	*light;

	obj = e->obj;
	light = e->light;
	error((fd = open(e->arg.file_scene, O_RDWR)));
	while (get_next_line(fd, &line) > 0)
	{
		!ft_strcmp(line, "camera") ? parse_camera(e, fd) : 0;
		if (!ft_strcmp(line, "light") && (light->next = create_light(fd)))
			light = light->next;
		if (!ft_strcmp(line, "object") && (obj->next = create_object(fd)))
			obj = obj->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	error((close(fd) + 1));
}

void	parse_camera(t_env *e, int fd)
{
	char	*line;

	init_camera(e);
	while (get_next_line(fd, &line) > 0 && line[0] != '}')
	{
		if (ft_strstr(line, "pos"))
			e->cam.pos = parse_vector(line);
		if (ft_strstr(line, "rot"))
			e->cam.rot = parse_vector(line);
		if (ft_strstr(line, "fov"))
			e->cam.fov = ft_atof(ft_strstr(line, "=") + 1);
		if (ft_strstr(line, "gamma"))
			e->cam.invgamma = 1 / ft_atof(ft_strstr(line, "=") + 1);
		if (ft_strstr(line, "maxdepth"))
			e->cam.maxdepth = ft_atoi(ft_strstr(line, "=") + 1);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	e->arg.f != -1 ? e->cam.fov = e->arg.f : 0;
	e->arg.m != -1 ? e->cam.maxdepth = e->arg.m : 0;
	e->arg.g != -1 ? e->cam.invgamma = 1.0 / e->arg.g : 0;
	e->arg.x != INFINITY ? e->cam.rot.x = e->arg.x : 0;
	e->arg.y != INFINITY ? e->cam.rot.y = e->arg.y : 0;
	e->arg.z != INFINITY ? e->cam.rot.z = e->arg.z : 0;
	e->cam.maxdepth < 0 ? e->cam.maxdepth = 0 : 0;
}

t_lgt	*create_light(int fd)
{
	char	*line;
	t_lgt	*light;

	error((int)(light = (t_lgt*)malloc(sizeof(t_lgt))));
	init_light(light);
	while (get_next_line(fd, &line) > 0 && line[0] != '}')
	{
		if (ft_strstr(line, "pos"))
			light->pos = parse_vector(line);
		if (ft_strstr(line, "color"))
			light->color = hex_to_color(ft_atoi_base(line, 16));
		if (ft_strstr(line, "intensity"))
			light->intensity = ft_atof(ft_strstr(line, "=") + 1);
		if (ft_strstr(line, "linear"))
			light->linear = ft_atof(ft_strstr(line, "=") + 1);
		if (ft_strstr(line, "quadratic"))
			light->quadratic = ft_atof(ft_strstr(line, "=") + 1);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	light->next = NULL;
	return (light);
}

t_obj	*create_object(int fd)
{
	char	*line;
	t_obj	*obj;

	error((int)(obj = (t_obj*)malloc(sizeof(t_obj))));
	init_object(obj);
	while (get_next_line(fd, &line) > 0 && line[0] != '}')
	{
		if (ft_strstr(line, "type"))
			obj->type = parse_type(line);
		if (ft_strstr(line, "pos"))
			obj->pos = parse_vector(line);
		if (ft_strstr(line, "dir"))
			obj->dir = parse_vector(line);
		if (ft_strstr(line, "scale"))
			obj->scale = ft_atof(ft_strstr(line, "=") + 1);
		if (ft_strstr(line, "material"))
			obj->mat = parse_material(fd);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	obj->next = NULL;
	return (obj);
}

t_mat	parse_material(int fd)
{
	char	*line;
	t_mat	mat;

	init_material(&mat);
	while (get_next_line(fd, &line) > 0 && line[1] != '}')
	{
		if (ft_strstr(line, "color"))
			mat.color = hex_to_color(ft_atoi_base(line, 16));
		if (ft_strstr(line, "ambient"))
			mat.ambient = ft_atof(ft_strstr(line, "=") + 1);
		if (ft_strstr(line, "diffuse"))
			mat.diffuse = ft_atof(ft_strstr(line, "=") + 1);
		if (ft_strstr(line, "specular"))
			mat.specular = ft_atof(ft_strstr(line, "=") + 1);
		if (ft_strstr(line, "shininess"))
			mat.shininess = ft_atof(ft_strstr(line, "=") + 1);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (mat);
}
