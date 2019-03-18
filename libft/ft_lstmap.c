/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:44:21 by rstracke          #+#    #+#             */
/*   Updated: 2018/12/10 14:45:30 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;
	t_list *buf;

	if (!lst || !f)
		return (NULL);
	buf = f(lst);
	if (!(new = ft_lstnew(buf->content, buf->content_size)))
		return (NULL);
	head = new;
	lst = lst->next;
	while (lst)
	{
		buf = f(lst);
		if (!(new->next = ft_lstnew(buf->content, buf->content_size)))
		{
			ft_lstdel(&head, &ft_del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
