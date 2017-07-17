#include "ft_exec_private.h"

void			ft_exec_wait_all(t_proc **all)
{
	pid_t		pid;
	int			status;
	int			i;

	while ((pid = wait(&status)))
	{
		i = 0;
		while (all[i]->pid != pid)
			i++;
		all[i]->status = status;
	}
}
