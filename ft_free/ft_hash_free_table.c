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

extern t_hash **g_table;

static void	free_elem(t_hash *elem)
{
	t_hash	*tmp;

	while (elem)
	{
		tmp = elem;
		elem = elem->next;
		free(tmp->command);
		free(tmp->filename);
		free(tmp);
	}
}

void		ft_hash_free_table(void)
{
	int		i;

	if (!g_table)
		return ;
	i = 0;
	while (i < HASH_SIZE)
	{
		if (g_table[i])
			free_elem(g_table[i]);
		i++;
	}
	free(g_table);
	g_table = NULL;
}
