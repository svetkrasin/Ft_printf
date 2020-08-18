/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:07:19 by svet              #+#    #+#             */
/*   Updated: 2020/07/20 16:30:21 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strappend(char **dst, char const *src)
{
	char	*new_str;

	if (dst == NULL)
		return (NULL);
	if ((new_str = ft_strjoin(*dst, src)) == NULL)
		return (NULL);
	ft_strdel(dst);
	return ((*dst = new_str));
}
