/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:10:49 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 20:31:51 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_BONUS_H
# define FT_LIST_BONUS_H
# include <sys/_types/_size_t.h>
# ifndef LIBFT_BONUS
#  include "ft_list.h"
# endif

void				ft_lstadd_front(t_list **lst, t_list *new);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));

/*
**# ifdef LIBFT_BONUS
**typedef struct		s_list
**{
**	void			*content;
**	struct s_list	*next;
**}					t_list;
**t_list				*ft_lstnew(void const *content);
**void				ft_lstiter(t_list *lst, void (*f)(void *));
**t_list				*ft_lstmap(t_list *lst, t_list *(*f)(void *),
**														void (*del)(void *));
**void				ft_lstrev(t_list **alst);
**# endif
*/

#endif
