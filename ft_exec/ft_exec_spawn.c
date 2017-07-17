#include "ft_exec_private.h"

void			ft_exec_dup(t_proc *proc)
{
	if (proc->dup[0] != 0)
		dup2(proc->dup[0], 0);
	if (proc->dup[1] != 1)
		dup2(proc->dup[1], 1);
	if (proc->dup[2] != 2)
		dup2(proc->dup[2], 2);
}

void			ft_exec_close_except(t_proc **all, t_proc *proc)
{
	int			i;

	i = 0;
	while (all[i])
	{
		if (all[i] != proc)
		{
			if (all[i]->dup[0] > 2)
				close(all[i]->dup[0]);
			if (all[i]->dup[1] > 2)
				close(all[i]->dup[1]);
			if (all[i]->dup[2] > 2)
				close(all[i]->dup[2]);
		}
		i += 1;
	}
}

void			ft_exec_spawn(t_proc **all, t_proc *proc)
{
	pid_t		pid;

	pid = fork();
	if (pid == 0)
	{
		ft_exec_dup(proc);
		ft_exec_close_except(all, proc);
		execve(proc->path, proc->argv, proc->env);
	}
	proc->pid = pid;
}
