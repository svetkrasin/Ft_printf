/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 10:19:47 by svet              #+#    #+#             */
/*   Updated: 2020/05/20 10:28:01 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include <sys/_types/_null.h>

size_t	ft_lstsize(t_list *lst)
{
	size_t size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		++size;
	}
	return (size);
}
