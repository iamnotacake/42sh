/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:54:05 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/20 19:54:18 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;

	l = NULL;
	if (!lst || !*(*f))
		return (NULL);
	if (!(l = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	l->content = f(lst)->content;
	l->content_size = f(lst)->content_size;
	l->next = ft_lstmap(lst->next, f);
	return (l);
}
