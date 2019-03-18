/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:12:37 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/10 14:53:09 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	i = -1;
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if ((dest == NULL) && (src == NULL))
		return (dest);
	if (src < dest)
	{
		while ((int)n > 0)
		{
			*(ptr_dest + n - 1) = *(ptr_src + n - 1);
			n--;
		}
	}
	else if (dest < src)
		while (++i < n)
			*(ptr_dest + i) = *(ptr_src + i);
	return (dest);
}
