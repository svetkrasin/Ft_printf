/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:29:21 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 19:52:36 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <sys/_types/_size_t.h>

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haysteck, const char *needle,
																	size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);

char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strncat(char *s1, char *s2, size_t n);
size_t			ft_strnlen(const char *str, size_t n);
long			ft_strtol(const char *nptr, char **endptr, int base);
char			*ft_strchrnul(const char *s, char c);

char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *str, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(size_t, char));

char			*ft_strappend(char **dst, char const *src);
char			*ft_strnappend(char **dst, char const *src, size_t n);
char			*ft_ltoa_base(long n, int base, int isupper);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strmap(char const *s, char (*f)(char));
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, size_t start, size_t len);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(size_t, char *));

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base);
char			*ft_ultoa_base(unsigned long n, int base, int isupper);

char			*ft_substr(char const *s, size_t start, size_t len);

#endif
