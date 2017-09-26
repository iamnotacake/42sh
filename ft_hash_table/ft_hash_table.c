/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:05:02 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/18 20:05:04 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"
#include "ft_free_private.h"

static char	**get_path(const char *const env[])
{
	char	**ret;
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH", 4) && env[i][4] == '=')
		{
			tmp = ft_strdup(&env[i][6]);
			ret = ft_strsplit(tmp, ':');
			free(tmp);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

static void	init_table(t_hash **table, char **path)
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
				ft_hash_add(table, entry->d_name, filename);
			free(filename);
		}
		if (dir)
			closedir(dir);
		i++;
	}
}

static void	print_table(t_hash **table)
{
	t_hash	*entry;
	int		i;
	int		n;

	i = 0;
	while (i < HASH_SIZE)
	{
		if ((entry = table[i]))
		{
			n = 1;
			while (entry->next)
			{
				entry = entry->next;
				n++;
			}
			ft_putnbr(n);
		}
		else
			write(1, "-", 1);
		write(1, " ", 1);
		if (!((i + 1) % 25))
			write(1, "\n", 1);
		i++;
	}
}

t_hash		**ft_hash_table(const char *const envp[])
{
	t_hash	**table;
	char	**path;

	if (!(path = get_path(envp)))
		return (NULL);
	table = ft_memalloc(sizeof(t_hash *) * HASH_SIZE + 1);
	init_table(table, path);
	print_table(table);
	ft_free_mas(path);
	return (table);
}
