/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:26:56 by svet              #+#    #+#             */
/*   Updated: 2020/05/25 13:31:14 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include <sys/_types/_null.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		lst = &new;
	else if (*lst != NULL)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
