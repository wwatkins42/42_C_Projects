/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:11:57 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/15 15:34:46 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	vec2_fmul(t_vec2 v, double m)
{
	t_vec2	r;

	r.x = v.x * m;
	r.y = v.y * m;
	return (r);
}
