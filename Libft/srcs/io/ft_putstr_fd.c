/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:12:40 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 20:07:12 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_io.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	(s != NULL) ? write(fd, s, ft_strlen(s)) : 0;
}
