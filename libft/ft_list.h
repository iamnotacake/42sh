/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:44:27 by mbraslav          #+#    #+#             */
/*   Updated: 2017/06/14 14:44:28 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

size_t				ft_lstlen(t_list *list);
t_list				*ft_lstgetlast(t_list *list);
void				ft_lstswap(t_list **list, t_list *x, t_list *y);
void				ft_lstsort(t_list **list, int (*cmp)(void *a, void *b));
void				ft_lstrsort(t_list **list, int (*cmp)(void *a, void *b));
void				ft_lstfreelist(t_list **list, \
									void (*freecont)(void *content));
void				ft_lstfreeelem(t_list **list, t_list *elem, \
									void (*freecont)(void *content));
void				ft_lstpushback(t_list **list, t_list *elem);
void				ft_lstpushfront(t_list **list, t_list *elem);
void				ft_lstinsert(t_list **list, \
									t_list *prev, t_list *list2, t_list *next);

void				ft_lstremoveelem(t_list **list, t_list *elem);
int					ft_lstisinlist(t_list *list, t_list *elem);
t_list				*ft_lstdup(t_list *list);
t_list				*ft_lstdupelem(t_list *elem);
t_list				*ft_lstfind(t_list *list, void *content,\
								size_t content_size);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

#endif
