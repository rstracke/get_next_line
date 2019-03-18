/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:51:50 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/08 17:57:10 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	res;
	long long	tmp;

	i = 0;
	sign = 1;
	res = 0;
	while (*(nptr + i) == '\n' || *(nptr + i) == '\t' || *(nptr + i) == '\r' ||
			*(nptr + i) == '\v' || *(nptr + i) == '\f' || *(nptr + i) == ' ')
		i++;
	if (*(nptr + i) == '-')
		sign = -1;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
		i++;
	while (*(nptr + i) && *(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		tmp = res;
		res = res * 10 + (*(nptr + i++) - '0');
		if (tmp > res)
			return ((sign == 1) ? (-1) : (0));
	}
	return ((int)(res * sign));
}
