#ifndef __FT_EXEC_PRIVATE_H
# define __FT_EXEC_PRIVATE_H

# include <sys/wait.h>
# include "ft_exec.h"

void			ft_exec_dup(t_proc *proc);
void			ft_exec_close_except(t_proc **all, t_proc *proc);
void			ft_exec_spawn(t_proc **all, t_proc *proc);

void			ft_exec_wait_all(t_proc **all);

#endif
