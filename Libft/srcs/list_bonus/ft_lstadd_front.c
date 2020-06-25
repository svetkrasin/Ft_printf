/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:15:48 by svet              #+#    #+#             */
/*   Updated: 2020/05/25 13:32:13 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include <sys/_types/_null.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		lst = &new;
	else if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
