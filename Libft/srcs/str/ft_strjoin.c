/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:51:23 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/20 15:01:02 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n1;
	size_t	n2;
	char	*fstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	if ((fstr = ft_strnew(n1 + n2)) == NULL)
		return (NULL);
	ft_memcpy(fstr + n1, s2, n2);
	return (ft_memcpy(fstr, s1, n1));
}
