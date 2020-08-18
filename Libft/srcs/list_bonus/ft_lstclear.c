/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:44:50 by svet              #+#    #+#             */
/*   Updated: 2020/07/21 21:19:12 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_list_bonus.h"
#include <sys/_types/_null.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (lst != NULL)
		while (*lst != NULL)
		{
			del((*lst)->content);
			tmp = (*lst)->next;
			ft_memdel((void **)lst);
			*lst = tmp;
		}
	lst = NULL;
}
