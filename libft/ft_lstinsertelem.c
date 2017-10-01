/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:42:07 by mbraslav          #+#    #+#             */
/*   Updated: 2017/06/14 14:42:09 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstinsert(t_list **list, t_list *prev, t_list *list2, t_list *next)
{
	t_list	*last;

	if (!*list || !list2)
		return ;
	last = ft_lstgetlast(list2);
	if (prev)
		prev->next = list2;
	else
		*list = list2;
	list2->prev = prev;
	if (next)
		next->prev = last;
	last->next = next;
}
