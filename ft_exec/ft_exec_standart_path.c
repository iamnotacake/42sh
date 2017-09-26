/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_standart_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:37:39 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 17:37:41 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec_private.h"

extern t_hash	**g_table;

char	*wt_pth_com(char *pth, char *com)
{
	char	*f_path;
	char	*tmp;

	tmp = ft_strjoin(pth, "/");
	f_path = ft_strjoin(tmp, com);
	free(tmp);
	return (f_path);
}

void	wt_free_pth(char **pth)
{
	int	i;

	i = 0;
	while (pth[i])
	{
		free(pth[i]);
		i++;
	}
	free(pth[i]);
	free(pth);
}

char	**wt_pth(char **env, char *str)
{
	int		e;
	int		i;
	char	*tmp;
	char	**pth;

	e = 0;
	while (env[e])
	{
		i = 0;
		while (env[e][i] == str[i])
		{
			if (env[e][i + 1] == '=')
			{
				tmp = ft_strdup(env[e] + i + 2);
				pth = ft_strsplit(tmp, ':');
				free(tmp);
				return (pth);
			}
			i++;
		}
		e++;
	}
	return (NULL);
}

int		ft_exec_old_method(t_proc **proc)
{
	char	**pth;
	int		i;
	char	*f_pth;

	i = 0;
	if (!(pth = wt_pth(g_env_g, "PATH")))
		return (-1);
	while (pth[i])
	{
		f_pth = wt_pth_com(pth[i], (*proc)->argv[0]);
		if (!access(f_pth, X_OK))
		{
			wt_free_pth(pth);
			(*proc)->path = f_pth;
			ft_hash_add(g_table, (*proc)->argv[0], (*proc)->path);
			return (0);
		}
		free(f_pth);
		i++;
	}
	wt_free_pth(pth);
	return (-1);
}

int		ft_exec_standart_path(t_proc **proc)
{
	char	*com;

	if ((com = ft_hash_find(g_table, (*proc)->argv[0])) != NULL)
	{
		(*proc)->path = com;
		if (!access((*proc)->path, X_OK))
		{
		// 	printf("hash: %s\n", (*proc)->path);
			return (0);
		}
		ft_hash_remove(g_table, (*proc)->argv[0]);
		if (ft_exec_old_method(proc) == 0)
		{
			if (!access((*proc)->path, X_OK))
			{
				// printf("re_old: %s\n", (*proc)->path);
				return (0);
			}
		}
	}
	else if (ft_exec_old_method(proc) == 0)
	{
		// printf("old: %s\n", (*proc)->path);
		return (0);
	}
	return (-1);
}
