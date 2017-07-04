#ifndef __FT_EXEC_H
# define __FT_EXEC_H

typedef struct	s_proc
{
	char		*path;
	char		**argv;
	char		**env;
	// {0, 1, 2} are default
	int			dup[3];
}				t_proc;

int				ft_exec(t_proc **proc);

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
