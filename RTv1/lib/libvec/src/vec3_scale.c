/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:47:42 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/15 15:20:39 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vec3_scale(t_vec3 v, double scale)
{
	vec3_normalize(&v);
	v.x *= scale;
	v.y *= scale;
	v.z *= scale;
	return (v);
}
