/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:42:30 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 18:10:12 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H
# include <sys/_types/_size_t.h>

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist				*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem));

size_t				ft_dlstlength(t_dlist *lst);
t_dlist				*ft_dlstedge(t_dlist *alst, int isforward);
int					ft_dlstloop(t_dlist *alst);
int					ft_dlstunloop(t_dlist *alst);

#endif
