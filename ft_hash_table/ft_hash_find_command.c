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

static int		ft_hash_function(char *command)
{
	unsigned int	hash;
	int				i;

	hash = 0;
	i = 0;
	while (command[i])
	{
		hash = (hash << 5) + (hash >> sizeof(hash)) + command[i];
		i++;
	}
	return (hash % HASH_SIZE);
}

static t_hash	*new_entry(char *command, char *filename)
{
	t_hash	*new;

	if (!(new = malloc(sizeof(t_hash))))
		return (NULL);
	new->command = ft_strdup(command);
	new->filename = ft_strdup(filename);
	new->next = NULL;
	return (new);
}

void			ft_hash_add(t_hash **table, char *command, char *filename)
{
	t_hash	*entry;
	t_hash	*last;
	int		index;

	if (!(entry = new_entry(command, filename)))
		return ;
	index = ft_hash_function(command);
	if (!(table[index]))
		table[index] = entry;
	else
	{
		last = table[index];
		while (last->next)
			last = last->next;
		last->next = entry;
	}
}

void			ft_hash_remove(t_hash **table, char *command)
{
	t_hash	**entry;
	t_hash	*tmp;
	int		hash;

	if (!table || !command)
		return ;
	hash = ft_hash_function(command);
	if (table[hash])
	{
		entry = &table[hash];
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

char			*ft_hash_find(t_hash **table, char *command)
{
	int		hash;
	t_hash	*tmp;

	if (!table || !command)
		return (NULL);
	hash = ft_hash_function(command);
	if ((tmp = table[hash]))
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->command, command))
				return (ft_strdup(tmp->filename));
			tmp = tmp->next;
		}
	}
	return (NULL);
}
