#include "ft_exec_private.h"

int				ft_exec(t_proc **all)
{
	int			i;
	int			pipe_pair[2];

	i = 0;
	while (all[i])
	{
		if (all[i + 1])
		{
			pipe(pipe_pair);
			all[i]->dup[1] = pipe_pair[1];
			all[i + 1]->dup[0] = pipe_pair[0];
		}
		ft_exec_spawn(all, all[i]);
		i += 1;
	}
	ft_exec_wait_all(all);
	i = 0;
	while (all[i + 1])
		i += 1;
	return (all[i]->status);
}
