/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstloop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:12:40 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 19:54:52 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <sys/_types/_null.h>

int	ft_dlstloop(t_dlist *alst)
{
	t_dlist			*node;

	if (alst == NULL)
		return (-1);
	if ((node = ft_dlstedge(alst, 0)) == NULL)
		return (0);
	ft_dlstedge(alst, 1)->next = node;
	return (1);
}
