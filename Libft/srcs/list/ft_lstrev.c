/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 01:56:40 by svet              #+#    #+#             */
/*   Updated: 2020/05/25 11:22:07 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <sys/_types/_null.h>

void	ft_lstrev(t_list **alst)
{
	t_list *prev;
	t_list *next;

	if (alst == NULL || *alst == NULL)
		return ;
	prev = NULL;
	next = NULL;
	while (*alst != NULL)
	{
		next = (*alst)->next;
		(*alst)->next = prev;
		prev = *alst;
		*alst = next;
	}
	*alst = prev;
}
