/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:07:37 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/10 13:45:58 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_haystack;
	char	*ptr_needle;
	int		trigger;
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (*(haystack) && i++ + ft_strlen(needle) <= len)
	{
		ptr_needle = (char *)needle;
		ptr_haystack = (char*)haystack;
		if (*ptr_haystack == *ptr_needle)
		{
			trigger = 1;
			while (*ptr_needle && trigger)
			{
				trigger = trigger && (*ptr_haystack++ == *ptr_needle++);
			}
			if (trigger)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
