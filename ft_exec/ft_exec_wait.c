#include "ft_exec_private.h"

int			ft_exec_wait(t_proc **proc)
{
	int			status;
	t_proc		*tmp;
	int			result;

	result = 0;
	tmp = (*proc);
	ft_exec_proc_up(proc);
	// signal(SIGINT, SIG_IGN);
	while ((*proc))
	{
		// printf("if: %d\n", (*proc)->pid);
		if ((*proc)->pid)
		{
			g_proc = (*proc);
			waitpid((*proc)->pid, &status, WUNTRACED);
			g_proc = 0;
			// printf("pid wait: %d, status: %d\n", (*proc)->pid, status);
			(*proc)->status = status;
			if (status != 0)
				result = status;
		}
		(*proc) = (*proc)->next;
	}
	// ft_signals();
	(*proc) = tmp;
	return (result);
}
