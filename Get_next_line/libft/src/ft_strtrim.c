/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:33:44 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/03 18:07:24 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_the_end(char const *s, int i)
{
	while (s[i] != 0)
	{
		if (s[i] != ' ' && s[i] != ',' && s[i] != '\n' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*trim;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(trim = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != 0)
	{
		if (!ft_is_the_end(s, i))
		{
			trim[j] = s[i];
			j++;
		}
		i++;
	}
	trim[j] = 0;
	return (trim);
}
