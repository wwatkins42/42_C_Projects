/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 18:03:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 18:03:13 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_str(t_e *e, t_a *arg, int *i)
{
	if (arg->mod.l || arg->type == 'S')
		*i = print_str(va_arg(e->ap, char *), arg->width, arg->prec.prec);
	else
		*i = print_str(va_arg(e->ap, char *), arg->width, arg->prec.prec);
}
