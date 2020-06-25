/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:21:01 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/25 14:17:02 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static inline int	ft_bytememcmp(const void **str1,
						const void **str2, size_t *nbytes, size_t n)
{
	register const unsigned char	*s1;
	register const unsigned char	*s2;

	s1 = *(const unsigned char **)str1;
	s2 = *(const unsigned char **)str2;
	*nbytes -= n;
	while (n-- != 0)
		if (*s1++ != *s2++)
			return (*--s1 - *--s2);
	return (0);
}

static inline int	ft_optmemcmp(const void **const str1,
									const void **const str2, size_t *nbytes)
{
	const unsigned OP_T	*s1;
	const unsigned OP_T	*s2;
	register size_t		n;

	n = *nbytes;
	ft_bytememcmp(str1, str2, nbytes, ft_memaligncmp(str1, str2, n,
																OPT_SIZE));
	s1 = *(const unsigned OP_T **const)str1;
	s2 = *(const unsigned OP_T **const)str2;
	n /= OPT_SIZE;
	while (n-- != 0)
	{
		if (*s1 != *s2)
			return (ft_bytememcmp((const void **)&s1, (const void **)&s2,
														nbytes, OPT_SIZE));
			++s1;
		++s2;
	}
	*str1 = s1;
	*str2 = s2;
	*nbytes = OPT_SIZE - *nbytes & OPT_MASK;
	return (0);
}

int					ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const void **const	s1 = &str1;
	const void **const	s2 = &str2;
	size_t *const		nbytes = &n;
	unsigned int		res;

	if (n >= OPT_SIZE && (res = ft_optmemcmp(s1, s2, nbytes)) != 0)
		return (res);
	if (n != 0)
		return (ft_bytememcmp(s1, s2, nbytes, n));
	return (0);
}
