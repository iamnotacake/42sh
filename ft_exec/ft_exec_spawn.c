#include "ft_exec_private.h"
#include "ft_env.h"

extern int	g_parent;

void	ft_exec_dup(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (proc->dup[i] != i)
			dup2(proc->dup[i], i);
		i++;
	}
}

void	ft_exec_close_fd(t_proc *proc, int fl)
{
	int	i;

	i = 0;
	while (proc)
	{
		i = 0;
		while (i < 10)
		{
			if (proc->dup[i] != i && proc->dup[i] > 2)
			{
				// printf("close child: %d\n", proc->dup[i]);
				close(proc->dup[i]);
			}
			i++;
		}
		if (fl == -1)
			proc = proc->prev;
		else if (fl == 1)
			proc = proc->next;
	}
}

void	ft_exec_close_except(t_proc *proc)
{
	t_proc	*prev;
	t_proc	*next;

	prev = proc->prev;
	next = proc->next;
	ft_exec_close_fd(prev, -1);
	ft_exec_close_fd(next, 1);
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

void	ft_exec_spawn(t_proc **proc)
{
	pid_t		pid;

	pid = fork();
	if (pid == 0)
	{
		g_parent = 0;
		ft_exec_close_except(*proc);
		ft_exec_dup(*proc);
		if (!ft_exec_is_builtin(proc))
			execve((*proc)->path, (*proc)->argv, g_env_g);
	}
	// printf("pid: %d\n", pid);
	(*proc)->pid = pid;
}
