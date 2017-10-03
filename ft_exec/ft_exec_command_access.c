/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command_access.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:19:21 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/07 17:19:25 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec_private.h"
// #include <sys/stat.h>

int		wt_last_slash(char **argv)
{
	int	sl;
	int	i;

	i = 0;
	sl = 0;
	while (argv[0][i] != '\0')
	{
		if (argv[0][i] == '/')
			sl = i;
		i++;
	}
	return (sl);
}

int		ft_exec_check_on_exe(t_proc **proc)
{
	int	i;

	i = 0;
	while ((*proc)->argv[0][i])
	{
		if (((*proc)->argv[0][i] == '.' ||
			(*proc)->argv[0][i] == '/'))
			return (1);
		i++;
	}
	return (0);
}

int		ft_exec_user_path(t_proc **proc)
{
	int			sl;
	char		*tmp;
	struct stat	st;

	if (!access((*proc)->argv[0], X_OK))
	{
		sl = wt_last_slash((*proc)->argv);
		(*proc)->path = ft_strdup((*proc)->argv[0]);
		if (lstat((*proc)->path, &st) == 0)
		{
			if (S_ISDIR(st.st_mode) || S_ISLNK(st.st_mode))
				return (-1);
		}
		if (!ft_exec_check_on_exe(proc))
			return (-1);
		*((*proc)->argv[0] + sl) = '\0';
		tmp = ft_strdup((*proc)->argv[0] + sl + 1);
		free((*proc)->argv[0]);
		(*proc)->argv[0] = ft_strdup(tmp);
		free(tmp);
		return (0);
	}
	return (-1);
}

void	ft_exec_error(t_proc **proc)
{
	int	old2;

	old2 = 0;
	if ((*proc)->dup[2] != 2)
	{
		old2 = dup(2);
		dup2((*proc)->dup[2], 2);
	}
	ft_putstr_fd("wtf?: command not found: ", 2);
	ft_putendl_fd((*proc)->argv[0], 2);
	if (old2)
	{
		dup2(old2, 2);
	}
}

int		ft_exec_command_access(t_proc **proc)
{
	if (ft_exec_user_path(proc) == 0)
	{
		ft_exec_spawn(proc);
		return (0);
	}
	else if (ft_exec_standart_path(proc) == 0)
	{
		ft_exec_spawn(proc);
		return (0);
	}
	ft_exec_error(proc);
	return (-1);
}
