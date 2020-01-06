/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:14:30 by skrasin           #+#    #+#             */
/*   Updated: 2019/12/03 15:32:42 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 4096
#define COUNT_SIZE 4096

static void		ft_read_write(int fd)
{
	char	buf[BUFF_SIZE];
	size_t	count;
	ssize_t	len;

	count = COUNT_SIZE;
	len = 1;
	while (len)
	{
		len = read(fd, buf, count);
		write(STDOUT_FILENO, buf, len);
	}
	write(STDOUT_FILENO, "\n", 1);
}

void			ft_display_file(const char *name)
{
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return ;
	ft_read_write(fd);
	close(fd);
}
