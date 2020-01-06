/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:53:20 by skrasin           #+#    #+#             */
/*   Updated: 2019/11/15 18:56:27 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	fresh = NULL;
	if (f)
	{
		while (lst)
		{
			ft_lstadd(&fresh, f(lst));
			lst = (*lst).next;
		}
		ft_lstrev(&fresh);
	}
	return (fresh);
}
