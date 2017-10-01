/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:20:03 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 15:26:44 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

int		ft_history_if(t_proc **proc)
{
	int	st;

	st = -1;
	if (!ft_strcmp("history", (*proc)->argv[0]))
		st = ft_history_stdout_clear(proc);
	else if ((*proc)->argv[0][0] == '!')
		st = ft_history_stdin(proc);
	return (st);
}

int		ft_history_print(t_proc **proc)
{
	int	st;
	int	old1;

	st = -1;
	old1 = 0;
	if ((*proc)->dup[1] != 1)
	{
		old1 = dup(1);
		dup2((*proc)->dup[1], 1);
	}
	st = ft_history_if(proc);
	if (old1)
	{
		dup2(old1, 1);
	}
	return (st);
}
