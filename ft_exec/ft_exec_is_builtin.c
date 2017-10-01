/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_is_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:44:08 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:44:10 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec_private.h"
#include "ft_env.h"

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putstr(env[i]);
		write(1, "\n", 1);
		i++;
	}
	exit(0);
}

void	ft_echo(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		ft_putstr(argv[i]);
		if (argv[i + 1])
			ft_putstr(" ");
	}
	ft_putstr("\n");
	exit(0);
}

int		ft_exec_is_builtin(t_proc **proc)
{
	if (!ft_strcmp("env", (*proc)->argv[0]))
	{
		ft_env(g_env_g);
		return (1);
	}
	else if (!ft_strcmp("echo", (*proc)->argv[0]))
	{
		ft_echo((*proc)->argv);
		return (1);
	}
	return (0);
}
