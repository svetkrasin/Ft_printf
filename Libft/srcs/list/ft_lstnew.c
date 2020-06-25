/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:36:51 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/25 11:21:16 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_memory.h"
#include <stdlib.h>
#include <sys/_types/_null.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL || ((*list).content = malloc(content_size)) == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content_size = content_size;
		list->content = ft_memcpy(list->content, content,
			content_size);
	}
	list->next = NULL;
	return (list);
}
