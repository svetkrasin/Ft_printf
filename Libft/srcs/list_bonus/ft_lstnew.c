/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:36:51 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/20 10:59:07 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include "ft_memory.h"
#include "ft_string.h"
#include <sys/_types/_null.h>

t_list	*ft_lstnew(void const *content)
{
	t_list *list;
	size_t content_size;

	if ((list = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		content_size = ft_strlen(content);
		if ((list->content = ft_memalloc(content_size)) != NULL)
		{
			list->content = ft_memcpy(list->content, content, content_size);
			list->next = NULL;
			return (list);
		}
	}
	list->content = NULL;
	list->next = NULL;
	return (list);
}
