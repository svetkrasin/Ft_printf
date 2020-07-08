/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:00:39 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/29 21:35:58 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>
#define BUFF_SIZE	4096
#define	FD_N		content_size

static inline t_list	*ft_lstsearch(size_t fd)
{
	static t_list	*store = NULL;
	t_list			*node;
	char			*tmp;

	node = store;
	while (node != NULL)
	{
		if (node->FD_N == fd)
			return (node);
		node = node->next;
	}
	tmp = ft_strnew(BUFF_SIZE);
	ft_lstadd(&store, ft_lstnew(tmp, BUFF_SIZE + 1));
	free(tmp);
	if (store == NULL)
		return (NULL);
	store->FD_N = fd;
	return (store);
}

int						ft_getline(const int fd, char **line)
{
	ssize_t			len;
	t_list			*node;
	char			buf[BUFF_SIZE + 1];
	char			*nl;

	if (fd < 0 || line == NULL || read(fd, 0, 0) == -1 ||
											(node = ft_lstsearch(fd)) == NULL)
		return (-1);
	while ((nl = ft_strchr(node->content, '\n')) == NULL)
	{
		if ((len = read(fd, buf, BUFF_SIZE)) <= 0)
			break ;
		buf[len] = '\0';
		ft_strappend((char **)&node->content, buf);
	}
	*line = nl ? ft_strsub(node->content, 0, nl - (char *)node->content) :
					ft_strdup(node->content);
	*(char *)node->content = '\0';
	nl ? ft_strappend((char **)&node->content, nl + 1) :
		ft_strappend((char **)&node->content, node->content);
	return ((**line == '\0' && !len) ? 0 : 1);
}
