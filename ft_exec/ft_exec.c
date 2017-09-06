#include "ft_exec_private.h"

// int				ft_exec(t_proc **all)
// {
// 	int			i;
// 	int			pipe_pair[2];

// 	i = 0;
// 	while (all[i])
// 	{
// 		if (all[i + 1])
// 		{
// 			pipe(pipe_pair);
// 			all[i]->dup[1] = pipe_pair[1];
// 			all[i + 1]->dup[0] = pipe_pair[0];
// 		}
// 		ft_exec_spawn(all, all[i]);
// 		i += 1;
// 	}
// 	ft_exec_wait_all(all);
// 	i = 0;
// 	while (all[i + 1])
// 		i += 1;
// 	return (all[i]->status);
// }

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
				// printf("close: %d\n", tmp->dup[i]);
				close(tmp->dup[i]);
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int		ft_exec(t_proc **proc)
{
	if (!(*proc))
	{
		printf("zalupa\n");
		return (-1);
	}

	ft_exex_proc_up(proc);
	ft_exec_close_parent_fd(*proc);
	printf("exec: %s\n", (*proc)->argv[0]);
	
	if (ft_strequ((*proc)->argv[0], "b"))
	{
		printf("RETURN (-1)\n");
		return (-1);
	}
	printf("RETURN (0)\n");
	return (0);
}
