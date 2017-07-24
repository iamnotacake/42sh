/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_hash_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:41:05 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/21 10:41:07 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free_private.h"

void	ft_free_elem(t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->com);
		free(tmp->pth);
		free(tmp);
	}
}

void	ft_hash_free_table(void)
{
	int		i;

	i = 0;
	if (g_table == NULL)
		return ;
	while(i < HASH_SIZE)
	{
		if (g_table[i].lst != NULL)
			ft_free_elem(g_table[i].lst); 
		i++;
	}
	free(g_table);
	g_table = NULL;
}
