/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:56:58 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:57:19 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec_private.h"

void	ft_exec_proc_up(t_proc **proc)
{
	if (!(*proc))
		return ;
	while ((*proc)->prev)
		(*proc) = (*proc)->prev;
}

void	ft_exec_close_parent_fd(t_proc *proc)
{
	t_proc	*tmp;
	int		i;

	tmp = proc;
	while (tmp)
	{
		i = 0;
		while (i < 10)
		{
			if (tmp->dup[i] != i && tmp->dup[i] > 2)
			{
				close(tmp->dup[i]);
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int		ft_exec_builtins(t_proc **proc)
{
	int	status;

	status = 1;
	if (!ft_strcmp("exit", (*proc)->argv[0]))
	{
		exit(0);
	}
	else if (!ft_strcmp("history", (*proc)->argv[0]) ||
		!ft_strncmp("!", (*proc)->argv[0], 1))
		status = ft_history_print(proc);
	else if (!ft_strcmp("setenv", (*proc)->argv[0]))
		status = ft_built_setenv(&g_env_g, (*proc)->argv);
	else if (!ft_strcmp("unsetenv", (*proc)->argv[0]))
		status = ft_built_unsetenv(&g_env_g, (*proc)->argv);
	else if (!ft_strcmp("cd", (*proc)->argv[0]))
		status = ft_built_cd(&g_env_g, (*proc)->argv);
	else if (!ft_strcmp("env", (*proc)->argv[0]) ||
			!ft_strcmp("echo", (*proc)->argv[0]))
	{
		ft_exec_spawn(proc);
		status = 0;
	}
	return (status);
}

int		ft_exec_check(t_proc **proc)
{
	int		status;

	status = -1;
	if ((status = ft_exec_builtins(proc)) == 1)
		status = ft_exec_standart(proc);
	return (status);
}

int		ft_exec(t_proc **proc)
{
	int		result;
	t_proc	*tmp;
	t_proc	*head;

	if (!(*proc) || !(*proc)->argv)
		return (-1);
	ft_exec_proc_up(proc);
	head = (*proc);
	tmp = (*proc);
	while ((*proc))
	{
		result = ft_exec_check(proc);
		if (result == -1)
			return (-1);
		tmp = (*proc);
		(*proc) = (*proc)->next;
	}
	ft_exec_close_parent_fd(head);
	result = ft_exec_wait(&head);
	(*proc) = tmp;
	return (result);
}
