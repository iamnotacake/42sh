#ifndef __FT_EXEC_PRIVATE_H
# define __FT_EXEC_PRIVATE_H

# include <sys/wait.h>
# include "ft_exec.h"
# include "ft_env.h"
// # include "ft_readline.h"
# include "ft_builtin.h"
# include "../libft/libft.h"
# include "ft_hash_table.h"

void			ft_exec_dup(t_proc *proc);
void			ft_exec_close_except(t_proc *proc);
void			ft_exec_spawn(t_proc **proc);
int			ft_exec_wait(t_proc **proc);
int		ft_exec_standart(t_proc **proc);
int		ft_exec_command_access(t_proc **proc);
int		ft_exec_standart_path(t_proc **proc);
void	ft_exec_proc_up(t_proc **proc);

#endif
