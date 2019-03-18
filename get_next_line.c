/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:38:23 by rstracke          #+#    #+#             */
/*   Updated: 2019/01/29 15:31:18 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_get_single_line(char **src)
{
	char			*dest;
	char			*ptr_lb;
	char			*old;

	if (!*src || !ft_strlen(*src))
		return (NULL);
	if (!(ptr_lb = ft_strchr(*src, '\n')))
		return (ft_strdup(*src));
	if (!(dest = ft_strnew(ptr_lb - *src)))
		return (NULL);
	ft_memccpy(dest, *src, '\n', ptr_lb - *src);
	old = *src;
	*src = ft_strdup(ptr_lb + 1);
	free(old);
	return (dest);
}

static t_list		*ft_get_file(t_list **file, int fd)
{
	t_list			*tmp;

	tmp = *file;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	free(tmp->content);
	if (!(tmp->content = ft_strnew(0)))
		return (NULL);
	ft_lstadd(file, tmp);
	return (*file);
}

static int			ft_readline(char **content, int fd)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(*content, buff);
		free(*content);
		*content = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*file;
	char			buff[BUFF_SIZE + 1];
	t_list			*current;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	current = ft_get_file(&file, fd);
	if (ft_strchr((char *)current->content, '\n'))
	{
		*line = ft_get_single_line((char **)&current->content);
		return (1);
	}
	if (!(ft_readline((char **)&current->content, current->content_size)))
	{
		if (!(*line = ft_get_single_line((char **)&current->content)))
			return (0);
		else
		{
			ft_strclr(current->content);
			return (1);
		}
	}
	if (!(*line = ft_get_single_line((char **)&current->content)))
		return (0);
	return (1);
}
