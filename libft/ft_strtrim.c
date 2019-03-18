/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:37:23 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/10 13:55:04 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*pos[2];
	char		*str_trim;
	int			len;
	int			i;

	pos[0] = NULL;
	pos[1] = NULL;
	str_trim = NULL;
	i = -1;
	if (s)
	{
		len = ft_strlen(s) - 1;
		while (*(s + ++i))
		{
			if (!ft_iswhitespace(*(s + i)) && !pos[0])
				pos[0] = (char *)(s + i);
			if (!ft_iswhitespace(*(s + len)) && !pos[1])
				pos[1] = (char *)(s + len + 1);
			len--;
		}
		str_trim = ft_strsub(s, (unsigned int)(pos[0] - s), pos[1] - pos[0]);
	}
	return (str_trim);
}
