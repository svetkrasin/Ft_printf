/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:00:39 by skrasin           #+#    #+#             */
/*   Updated: 2019/12/03 16:38:31 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>
#define BUFF_SIZE 4096

static t_list	*ft_lstsearch(size_t content_size)
{
	static t_list	*store = NULL;
	t_list			*node;
	char			*tmp;

	node = store;
	while (node)
	{
		if (node->content_size == content_size)
			return (node);
		node = node->next;
	}
	tmp = ft_strnew(BUFF_SIZE);
	ft_lstadd(&store, ft_lstnew(tmp, BUFF_SIZE + 1));
	free(tmp);
	if (store)
	{
		store->content_size = content_size;
		return (store);
	}
	else
		return (NULL);
}

static char		*ft_strextend(char **dst, char const *src)
{
	char	*tmp;
	size_t	n1;

	if (dst && *dst && src)
	{
		tmp = *dst;
		n1 = ft_strlen(*dst);
		if ((*dst = ft_memalloc(n1 + ft_strlen(src) + 1)))
		{
			*dst = ft_memcpy(*dst, tmp, n1 + 1);
			while (*src)
				*(*dst + n1++) = *src++;
			*(*dst + n1) = '\0';
		}
		free(tmp);
	}
	return (*dst);
}

int				ft_get_next_line(const int fd, char **line)
{
	ssize_t			len;
	t_list			*node;
	char			buf[BUFF_SIZE + 1];
	char			*nl;

	if (fd < 0 || !line || read(fd, 0, 0) || !(node = ft_lstsearch(fd)))
		return (-1);
	while (!(nl = ft_strchr(node->content, '\n')))
	{
		if ((len = read(fd, buf, BUFF_SIZE)) <= 0)
			break ;
		buf[len] = '\0';
		ft_strextend((char **)&node->content, buf);
	}
	*line = nl ? ft_strsub(node->content, 0, nl - (char *)node->content) :
					ft_strdup(node->content);
	*(char *)node->content = '\0';
	nl ? ft_strextend((char **)&node->content, nl + 1) :
		ft_strextend((char **)&node->content, node->content);
	return ((**line == '\0' && !len) ? 0 : 1);
}
