/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:32:09 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/08 20:35:47 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	trigger;
	int		i;
	int		j;
	int		k;

	trigger = 0;
	i = -1;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*(haystack + ++i) && !trigger)
	{
		if (*(haystack + i) == *(needle + 0))
		{
			trigger = 1;
			j = 0;
			k = i;
			while (*(needle + j))
				if (*(needle + j++) != *(haystack + k++))
					trigger = 0;
			if (trigger)
				return ((char *)(haystack + i));
		}
	}
	return (NULL);
}
