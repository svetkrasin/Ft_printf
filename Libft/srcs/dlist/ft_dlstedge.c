/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstedge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:56:44 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 20:45:13 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <sys/_types/_null.h>

t_dlist	*ft_dlstedge(t_dlist *alst, int isforward)
{
	const t_dlist *const	ref = alst;
	t_dlist					*node;

	if (alst == NULL)
		return (NULL);
	if (isforward)
		while ((node = alst->next) != NULL && node != ref)
			alst = node;
	else
		while ((node = alst->prev) != NULL && node != ref)
			alst = node;
	return (node == ref ? NULL : alst);
}
