/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:56:57 by svet              #+#    #+#             */
/*   Updated: 2020/08/14 19:03:08 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <sys/_types/_null.h>

size_t	ft_lstlength(t_list *head)
{
	size_t	n;

	n = 0;
	while (head != NULL)
	{
		++n;
		head = head->next;
	}
	return (n);
}
