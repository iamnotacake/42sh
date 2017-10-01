/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:35:17 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/10/01 14:35:22 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_EXEC_H
# define __FT_EXEC_H

# include <unistd.h>

/*
** default {0, 1, 2}, dup2(...) if not default
** process ID, returned by fork()
** exit status // pid = wait(&status)
*/

typedef struct		s_proc
{
	char			*path;
	char			**argv;
	int				dup[10];
	pid_t			pid;
	int				status;
	struct s_proc	*prev;
	struct s_proc	*next;
}					t_proc;

int					ft_exec(t_proc **proc);

#endif
