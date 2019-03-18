/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:01:13 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/08 20:02:20 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(dest);
	while (*(src + i) && (i < n))
	{
		*(dest + len) = *(src + i);
		i++;
		len++;
	}
	*(dest + len) = '\0';
	return (dest);
}
