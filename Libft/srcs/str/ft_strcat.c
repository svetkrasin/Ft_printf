/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:57:29 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/15 18:00:13 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

char	*ft_strcat(char *s1, const char *s2)
{
	ft_memcpy(s1 + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s1);
}
