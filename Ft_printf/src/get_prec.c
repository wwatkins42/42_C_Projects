/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:49:44 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 17:49:58 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_prec(const char *format, int i, t_a *arg)
{
	int	tmp;
	int	mult;
	int	re;

	mult = 1;
	re = 0;
	if (format[i] == '.')
		i++;
	tmp = i;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	while (i > tmp)
	{
		re++;
		arg->prec.prec = arg->prec.prec + (format[--i] - '0') * mult;
		mult *= 10;
	}
	return (i + re);
}
