/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_create_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:46:37 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/19 20:46:38 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"

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

void			ft_add_to_table(char *command, char *filename)
{
	t_hash	*entry;
	t_hash	*last;
	int		index;

	if (!(entry = new_entry(command, filename)))
		return ;
	index = ft_hash_function(command);
	if (!(g_table[index]))
		g_table[index] = entry;
	else
	{
		last = g_table[index];
		while (last->next)
			last = last->next;
		last->next = entry;
	}
}

void			ft_hash_create_lst(char **path)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*filename;
	char			*tmp;
	int				i;

	i = 0;
	while (path[i])
	{
		dir = opendir(path[i]);
		while (dir && (entry = readdir(dir)))
		{
			tmp = ft_strjoin(path[i], "/");
			filename = ft_strjoin(tmp, entry->d_name);
			free(tmp);
			if (!access(filename, X_OK) && \
				(entry->d_type == DT_REG || entry->d_type == DT_LNK))
				ft_add_to_table(entry->d_name, filename);
			free(filename);
		}
		if (dir)
			closedir(dir);
		i++;
	}
}
