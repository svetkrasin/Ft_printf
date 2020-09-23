/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:53:20 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/22 18:07:18 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <sys/_types/_null.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	if (f == NULL)
		return (NULL);
	fresh = NULL;
	while (lst != NULL)
	{
		ft_lstadd(&fresh, f(lst));
		lst = lst->next;
	}
	ft_lstrev(&fresh);
	return (fresh);
}
