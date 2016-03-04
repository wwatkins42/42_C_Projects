/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:59:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/04 09:47:54 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_mem(void *p, t_a *arg)
{
	int	len;
	int	plen;

	len = 2;
	plen = len + nbr_len_base((long)p, 16);
	arg->width -= plen;
	while (!arg->flag.mn && !arg->flag.zr && --arg->width >= 0 && (len++))
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
	write(1, "0x", 2);
	len += print_base(arg, (long)p, 16, 'a');
	while ((arg->flag.mn || arg->flag.zr) && --arg->width >= 0 && (len++))
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
	return (len);
}
