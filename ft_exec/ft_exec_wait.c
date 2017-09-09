#include "ft_exec_private.h"

void			ft_exec_wait(t_proc **proc)
{
	// pid_t		pid;
	int			status;
	t_proc		*tmp;

	tmp = (*proc);
	// printf("%d\n", (*proc)->pid);
	ft_exec_proc_up(proc);
	// printf("DDDDDD\n");
	// printf("%d\n", (*proc)->pid);
	while ((*proc))
	{
		// printf("if: %d\n", (*proc)->pid);
		if ((*proc)->pid)
		{
			waitpid((*proc)->pid, &status, WUNTRACED);
			printf("pid wait: %d, status: %d\n", (*proc)->pid, status);
			(*proc)->status = status;
		}
		(*proc) = (*proc)->next;
	}
	(*proc) = tmp;
}
