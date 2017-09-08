#include "ft_exec_private.h"

void	ft_exex_proc_up(t_proc **proc)
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
				// printf("close parrent: %d\n", tmp->dup[i]);
				close(tmp->dup[i]);
			}
			i++;
		}
		tmp = tmp->next;
	}
}

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
}

int		ft_exec_builtins(t_proc **proc)
{
	int	status;

	status = 1;
	if (!ft_strcmp("exit", (*proc)->argv[0]))
		exit(0);
	else if (!ft_strcmp("setenv", (*proc)->argv[0]))
		status = ft_built_setenv(&g_env_g, (*proc)->argv);
	else if (!ft_strcmp("unsetenv", (*proc)->argv[0]))
		status = ft_built_unsetenv(&g_env_g, (*proc)->argv);
	else if (!ft_strcmp("cd", (*proc)->argv[0]))
		status = ft_built_cd(&g_env_g, (*proc)->argv);
	else if (!ft_strcmp("env", (*proc)->argv[0]))
		ft_env(g_env_g);
	return (status);
}

int		ft_exec_check(t_proc **proc)
{
	t_proc	*tmp;
	int		status;

	status = -1;
	if ((status = ft_exec_builtins(proc)) == 1)
		status = ft_exec_standart(proc);
	return (status);
}

int		ft_exec(t_proc **proc)
{
	int		status;
	int		result;
	t_proc	*tmp;
	t_proc	*head;

	if (!(*proc))
		return (-1);
	ft_exex_proc_up(proc);
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
	while (wait(&status) > 0)
		;
	(*proc) = tmp;
	ft_exex_proc_up(proc);
	return (result);
}
