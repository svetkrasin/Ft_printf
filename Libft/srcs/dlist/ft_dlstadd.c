/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:26:31 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/22 22:47:44 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <sys/_types/_null.h>

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (alst == NULL)
		alst = &new;
	else if (new != NULL)
	{
		new->prev = *alst;
		if (*alst != NULL)
			(*alst)->next = new;
		*alst = new;
	}
}
