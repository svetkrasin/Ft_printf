/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:00:39 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 19:58:01 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_list.h"
#include "ft_io.h"
#include <unistd.h>
#define BUFF_SIZE	4096
#define FD_N		content_size

static inline t_list	*ft_lstsearch(size_t fd)
{
	static t_list	*store = NULL;
	register t_list	*node;
	char			*tmp_str;
	t_list			*tmp_node;

	node = store;
	while (node != NULL)
	{
		if (node->FD_N == fd)
			return (node);
		node = node->next;
	}
	if ((tmp_str = ft_strnew(BUFF_SIZE)) == NULL)
		return (NULL);
	tmp_node = ft_lstnew(tmp_str, BUFF_SIZE + 1);
	ft_strdel(&tmp_str);
	if (tmp_node == NULL)
		return (NULL);
	ft_lstadd(&store, tmp_node);
	store->FD_N = fd;
	return (store);
}

int						ft_getline(const int fd, char **line)
{
	ssize_t			len;
	t_list			*node;
	register char	buf[BUFF_SIZE + 1];
	register char	*nl;

	if (fd < 0 || line == NULL || read(fd, 0, 0) == -1 ||
									(node = ft_lstsearch((size_t)fd)) == NULL)
		return (-1);
	len = 0;
	while ((nl = ft_strchr(node->content, '\n')) == NULL)
	{
		if ((len = read(fd, buf, BUFF_SIZE)) <= 0)
			break ;
		buf[len] = '\0';
		if (ft_strappend((char **)&node->content, buf) == NULL)
			return (-1);
	}
	*line = nl ? ft_strsub(node->content, 0,
		(size_t)(nl - (char *)node->content)) : ft_strdup(node->content);
	*(char *)node->content = '\0';
	if ((nl ? ft_strappend((char **)&node->content, nl + 1) :
		ft_strappend((char **)&node->content, node->content)) == NULL)
		return (-1);
	return ((**line == '\0' && !len) ? 0 : 1);
}
