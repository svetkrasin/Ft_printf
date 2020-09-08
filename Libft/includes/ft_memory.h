/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:05:49 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 17:50:51 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H
# include <sys/_types/_size_t.h>
# define REP_01L	0x0101010101010101UL
# define REP_08L	0x0808080808080808UL

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

void			*ft_mempcpy(void *dst, const void *src, size_t n);

unsigned long	ft_repcset(int c);
size_t			ft_optmemalign(const void *const s);
size_t			ft_memaligncmp(const void *const*const ds,
				const void *const*const sr, size_t nbytes, unsigned long align);
size_t			ft_memaligncmp_bwd(const void *const*const ds,
				const void *const*const sr, size_t nbytes, unsigned long align);

char			*ft_memappend(void **dst, char const *src, size_t dlen,
																size_t slen);

#endif
