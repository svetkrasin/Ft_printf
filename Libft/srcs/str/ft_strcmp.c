/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:46:35 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/25 13:44:58 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	register const unsigned char	*p1 = (const unsigned char *)s1;
	register const unsigned char	*p2 = (const unsigned char *)s2;
	register unsigned char			c1;
	register unsigned char			c2;

	c1 = *p1++;
	c2 = *p2++;
	while (c1  == c2)
	{
		if (c1 == '\0')
			return (c1 - c2);
		c1 = *p1++;
		c2 = *p2++;
	}
	return (c1 - c2);
}
