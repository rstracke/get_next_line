/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:35:21 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/08 19:36:08 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int len;

	len = (int)ft_strlen(dest);
	while (*src)
		*(dest + len++) = *(src++);
	*(dest + len) = '\0';
	return (dest);
}
