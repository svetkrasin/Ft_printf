/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstunloop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:30:31 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 17:23:49 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <sys/_types/_null.h>

int	ft_dlstunloop(t_dlist *alst)
{
	if (alst == NULL)
		return (-1);
	if (ft_dlstedge(alst, 0) != NULL)
		return (0);
	alst->prev->next = NULL;
	alst->prev = NULL;
	return (1);
}
