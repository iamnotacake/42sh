/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:57:09 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/10/01 14:57:14 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_EXEC_PRIVATE_H
# define __FT_EXEC_PRIVATE_H

# include <sys/wait.h>
# include "ft_exec.h"
# include "ft_env.h"
# include "ft_builtin.h"
# include "../libft/libft.h"
# include "ft_hash_table.h"
# include "ft_history.h"

/*
** # include "ft_readline.h"
*/

void	ft_exec_dup(t_proc *proc);
void	ft_exec_close_except(t_proc *proc);
void	ft_exec_spawn(t_proc **proc);
int		ft_exec_wait(t_proc **proc);
int		ft_exec_standart(t_proc **proc);
int		ft_exec_command_access(t_proc **proc);
int		ft_exec_standart_path(t_proc **proc);
void	ft_exec_proc_up(t_proc **proc);
int		ft_exec_is_builtin(t_proc **proc);

#endif
