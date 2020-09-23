/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:56:57 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 18:05:02 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <sys/_types/_null.h>

size_t	ft_dlstlength(t_dlist *lst)
{
	const int	isloop = ft_dlstunloop(lst);
	size_t		n;

	n = 0;
	lst = ft_dlstedge(lst, 0);
	while (lst != NULL)
	{
		++n;
		lst = lst->next;
	}
	if (isloop == 1)
		ft_dlstloop(lst);
	return (n);
}
