/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:47:42 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/15 15:36:42 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3i	vec3i(t_vec3 v)
{
	t_vec3i vi;

	vi = (t_vec3i) { (int)v.x, (int)v.y, (int)v.z };
	return (vi);
}
