/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:51:48 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/11 14:50:08 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	unsigned char	s;
	size_t			i;

	i = 0;
	s = (unsigned char)c;
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	while ((i < n))
	{
		*(ptr_dest + i) = *(ptr_src + i);
		if (*(ptr_src + i) == s)
			return ((void *)ptr_dest + i + 1);
		i++;
	}
	return (NULL);
}
