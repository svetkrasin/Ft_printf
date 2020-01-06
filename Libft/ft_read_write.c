/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:31:08 by skrasin           #+#    #+#             */
/*   Updated: 2019/12/03 15:47:41 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 4096
#define COUNT_SIZE 1024

void			ft_read_write(int fd)
{
	char		buf[BUFF_SIZE];
	size_t		count;
	ssize_t		len;

	count = COUNT_SIZE;
	len = 1;
	while (len)
	{
		len = read(fd, buf, count);
		write(STDOUT_FILENO, buf, len);
	}
	write(STDOUT_FILENO, "\n", 1);
}
