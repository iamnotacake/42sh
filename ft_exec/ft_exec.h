#ifndef __FT_EXEC_H
# define __FT_EXEC_H

# include <unistd.h>

typedef struct		s_proc
{
	char			*path;
	char			**argv;
	int				dup[10];	// default {0, 1, 2}, dup2(...) if not default
	pid_t			pid;		// process ID, returned by fork()
	int				status;		// exit status // pid = wait(&status)
	struct s_proc	*prev;
	struct s_proc	*next;
}					t_proc;

int					ft_exec(t_proc **proc);

#endif
