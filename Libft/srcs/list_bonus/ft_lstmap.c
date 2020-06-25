/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:53:20 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/20 14:35:15 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include <sys/_types/_null.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(void *), void (*del)(void *))
{
	t_list	*fresh;
	void	*p;

	fresh = NULL;
	if (f == NULL)
		return (fresh);
	while (lst != NULL)
	{
		if ((p = f(lst->content)) != NULL)
			ft_lstadd_back(&fresh, ft_lstnew(p));
		else
			del(p);
		lst = (*lst).next;
	}
	return (fresh);
}
