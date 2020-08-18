/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrbuilder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:16:24 by svet              #+#    #+#             */
/*   Updated: 2020/08/18 10:20:44 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"
#include <sys/_types/_null.h>

static inline int	count_len(t_list *out)
{
	int len;
	int size;

	len = 0;
	while (out != NULL)
	{
		size = out->content_size;
		if (INT_MAX - len < size)
			return (-1);
		else
			len += size;
		out = out->next;
	}
	return (len);
}

int					build_fstr(char **fstr , t_list *out_node)
{
	int len = count_len(out_node);
	int		size;
	t_list	*tmp;
	char	*str;

	if (len == -1)
		return (-2);
	if ((str = ft_strnew(len)) == NULL)
		return (-1);
	*fstr = str;
	while (out_node != NULL)
	{
		size = out_node->content_size;
		ft_memcpy(str, out_node->content, size);
		str += size;
		tmp = out_node;
		out_node = out_node->next;
		ft_lstdelone(&tmp, ft_lstdelcontent);
	}
	return (len);
}
