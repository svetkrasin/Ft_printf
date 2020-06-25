/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:23:27 by svet              #+#    #+#             */
/*   Updated: 2020/05/20 10:26:13 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include <sys/_types/_null.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
