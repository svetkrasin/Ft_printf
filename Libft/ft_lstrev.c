/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 01:56:40 by svet              #+#    #+#             */
/*   Updated: 2019/10/04 15:44:49 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void				ft_lstrev(t_list **alst)
{
	t_list *prev;
	t_list *next;

	if (alst && *alst)
	{
		prev = NULL;
		next = NULL;
		while (*alst)
		{
			next = (*alst)->next;
			(*alst)->next = prev;
			prev = *alst;
			*alst = next;
		}
		*alst = prev;
	}
}
