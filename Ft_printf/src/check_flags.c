/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:47:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/23 10:04:35 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_zero(t_a *arg)
{
	if (arg->flag.zr == 1 && (arg->type == 's' || arg->type == 'S' ||
		arg->type == 'p' || arg->type == 'c' || arg->type == 'C'))
		return (-1);
	if (arg->flag.zr == 1 && arg->flag.mn == 1)
		arg->flag.zr = 0;
	if (arg->flag.zr == 1 && arg->prec.pt == 1 && (arg->type == 'd' ||
		arg->type == 'i' || arg->type == 'o' || arg->type == 'u' ||
		arg->type == 'x' || arg->type == 'X' || arg->type == 'D'))
		arg->flag.zr = 0;
	return (0);
}

int	check_space(t_a *arg)
{
	if (arg->flag.sp == 1 && !(arg->type == 'i' || arg->type == 'd' ||
		arg->type == 'D' || arg->type == '%'))
		return (-1);
	if (arg->flag.sp == 1 && arg->flag.di == 1)
		return (-1);
	if (arg->flag.sp == 1 && arg->flag.pl == 1)
		arg->flag.sp = 0;
	return (0);
}

int	check_plus(t_a *arg)
{
	if (arg->flag.pl == 1 && !(arg->type == 'd' || arg->type == 'D' ||
		arg->type == 'i' || arg->type == '%'))
		return (-1);
	return (0);
}

int	check_diez(t_a *arg)
{
	if (arg->flag.di == 1 && !(arg->type == 'o' || arg->type == 'O' ||
		arg->type == 'x' || arg->type == 'X' || arg->type == '%'))
		return (-1);
	return (0);
}
