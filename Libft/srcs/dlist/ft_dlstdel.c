/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:00:03 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/22 16:46:02 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <sys/_types/_null.h>

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist *tmp;

	if (alst != NULL)
		while (*alst != NULL)
		{
			tmp = (*alst)->next;
			ft_dlstdelone(alst, del);
			*alst = tmp;
		}
}
