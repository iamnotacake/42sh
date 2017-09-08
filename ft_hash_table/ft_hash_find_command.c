/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_find_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:18:28 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/21 11:18:30 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table_private.h"

char	*ft_hash_find_command(char *com)
{
	int		hash;
	t_lst	*tmp;

	if (g_table == NULL || com == NULL)
		return (NULL);
	hash = ft_hash_function(com);
	if (g_table[hash].lst)
	{
		tmp = g_table[hash].lst;
		while (tmp)
		{
			if (!ft_strcmp(com, tmp->com))
				return (ft_strdup(tmp->pth));
			tmp = tmp->next;
		}
	}
	return (NULL);
}

void	ft_hash_remove_element(char *com)
{
	t_lst	*tmp;
	t_lst	*prev;
	t_lst	*next;

	if (g_table == NULL || com == NULL)
		return ;
	if (g_table[ft_hash_function(com)].lst)
	{
		tmp = g_table[ft_hash_function(com)].lst;
		while (tmp)
		{
			if (!ft_strcmp(com, tmp->com))
			{
				next = tmp->next;
				free(tmp->com);
				free(tmp->pth);
				free(tmp);
				prev->next = next;
				return ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}