/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:08:59 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/11 13:21:00 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putendl((char *)tmp->content);
		tmp = tmp->next;
	}
}
