/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:20:18 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/08 21:50:53 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(int num)
{
	int		i;

	i = (num <= 0) ? 1 : 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	int		num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_getlen(n);
	sign = (n < 0) ? 1 : 0;
	num = (n < 0) ? -n : n;
	if (!(str = ft_strnew((size_t)len)))
		return (NULL);
	while (len >= 0)
	{
		*(str + --len) = (num % 10 + '0');
		num /= 10;
	}
	if (sign == 1)
		*(str + 0) = '-';
	return (str);
}
