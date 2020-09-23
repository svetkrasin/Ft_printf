/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:07:01 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/22 15:36:49 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_dlist.h"
#include <sys/_types/_null.h>

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist *tmp;

	if (alst == NULL || *alst == NULL)
		return ;
	del((*alst)->content, (*alst)->content_size);
	if ((tmp = (*alst)->next) != NULL)
		tmp->prev = (*alst)->prev;
	if ((tmp = (*alst)->prev) != NULL)
		tmp->next = (*alst)->next;
	ft_memdel((void **)alst);
	*alst = NULL;
}
