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

int		ft_exec_user_path(t_proc **proc)
{
	int		sl;
	char	*tmp;

	if (!access((*proc)->argv[0], X_OK))
	{
		sl = wt_last_slash((*proc)->argv);
		(*proc)->path = ft_strdup((*proc)->argv[0]);
		*((*proc)->argv[0] + sl) = '\0';
		tmp = ft_strdup((*proc)->argv[0] + sl + 1);
		free((*proc)->argv[0]);
		(*proc)->argv[0] = ft_strdup(tmp);
		printf("HZ: %s\n", (*proc)->argv[0]);
		free(tmp);
		return (0);
	}
	return (-1);
}

int		ft_exec_command_access(t_proc **proc)
{
	if (ft_exec_user_path(proc) == 0)
	{
		printf("USER\n");
		return (0);
	}
	else if (ft_exec_standart_path(proc) == 0)
	{
		printf("STANDART\n");
		return (0);
	}
	write(2, "wtf?: command not found: ", 25);
	ft_putendl_fd((*proc)->argv[0], 2);
	return (-1);
}
