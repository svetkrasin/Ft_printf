/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:53:20 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/22 20:45:30 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <sys/_types/_null.h>

t_dlist	*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	const int	isloop = ft_dlstunloop(lst);
	t_dlist		*fresh;

	if (f == NULL)
		return (NULL);
	fresh = NULL;
	lst = ft_dlstedge(lst, 0);
	while (lst != NULL)
	{
		ft_dlstadd(&fresh, f(lst));
		lst = lst->next;
	}
	if (isloop == 1)
	{
		ft_dlstloop(lst);
		ft_dlstloop(fresh);
	}
	return (fresh);
}
