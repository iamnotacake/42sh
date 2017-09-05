/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:50:19 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/12 18:50:21 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free_private.h"

void	ft_free_close_fd(int *fd)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (fd[i] != i)
			close(fd[i]);
		i++;
	}
}

void	ft_free_proc(t_proc *proc)
{
	t_proc	*tmp;

	if (!proc)
		return ;
	while (proc->prev)
		proc = proc->prev;
	while (proc)
	{
		if (proc->path)
			free(proc->path);
		if (proc->argv)
			free(proc->argv);
		ft_free_close_fd(proc->dup);
		tmp = proc;
		proc = proc->next;
		free(tmp);
	}
}
