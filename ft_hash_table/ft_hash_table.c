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

void		ft_hash_table(const char *const envp[])
{
	char	**path;

	if (g_table != NULL)
		ft_hash_free_table();
	if (!(path = get_path(envp)))
		return ;
	g_table = ft_memalloc(sizeof(t_hash *) * HASH_SIZE + 1);
	ft_hash_create_lst(path);
	print_table(g_table);
	ft_free_mas(path);
}
