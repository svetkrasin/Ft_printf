/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:49:52 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/22 18:02:24 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <sys/_types/_null.h>

void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	const int isloop = ft_dlstunloop(lst);

	lst = ft_dlstedge(lst, 0);
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
	if (isloop == 1)
		ft_dlstloop(lst);
}
