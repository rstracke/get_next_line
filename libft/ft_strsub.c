/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:36:03 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/08 20:37:07 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *substr;

	if (!s)
		return (NULL);
	substr = ft_strnew(len);
	if (!substr)
		return (NULL);
	substr = ft_strncpy(substr, (s + start), len);
	return (substr);
}
