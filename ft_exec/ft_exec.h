#ifndef __FT_EXEC_H
# define __FT_EXEC_H

# include <unistd.h>

typedef struct	s_proc
{
	char		*path;
	char		**argv;
	char		**env;
	int			dup[3];	// default {0, 1, 2}, dup2(...) if not default
	pid_t		pid;	// process ID, returned by fork()
	int			status;	// exit status // pid = wait(&status)
}				t_proc;

int				ft_exec(t_proc **all);

// t_proc **p = malloc(sizeof(t_proc *) * 3);
// p[0] = ...;
// p[1] = ...;
// p[2] = NULL;
//
// int i = 0;
// while (proc[i]) {
// 	asdasdasd;
// 	i++;
// }

#endif
