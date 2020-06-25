/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:51:23 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/18 11:34:41 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"
#include <sys/_types/_null.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fstr;
	size_t	n1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n1 = ft_strlen(s1) + 1;
	if ((fstr = ft_memalloc(n1 + ft_strlen(s2) + 1)))
	{
		fstr = ft_memcpy(fstr, s1, n1);
		return (ft_strcat(fstr, s2));
	}
	return (NULL);
}
