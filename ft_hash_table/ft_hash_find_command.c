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

#include "ft_hash_table.h"

char	*ft_hash_find_command(char *command)
{
	int		hash;
	t_hash	*tmp;

	if (!g_table || !command)
		return (NULL);
	hash = ft_hash_function(command);
	if ((tmp = g_table[hash]))
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->command, command))
				return (ft_strdup(tmp->filename)); // ???
			tmp = tmp->next;
		}
	}
	return (NULL);
}

void	ft_hash_remove_element(char *command)
{
	t_hash	**entry;
	t_hash	*tmp;
	int		hash;

	if (!g_table || !command)
		return ;
	hash = ft_hash_function(command);
	if (g_table[hash])
	{
		entry = &g_table[hash];
		while (*entry)
		{
			if (!ft_strcmp((*entry)->command, command))
			{
				tmp = *entry;
				entry = &(*entry)->next;
				free(tmp->command);
				free(tmp->filename);
				free(tmp);
				return ;
			}
			entry = &(*entry)->next;
		}
	}
}
