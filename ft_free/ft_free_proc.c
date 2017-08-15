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

void	ft_free_proc(t_proc *proc)
{
	int		i;
	t_proc	*tmp;

	if (!proc)
		return ;
	while (proc->prev)
		proc = proc->prev;
	while (proc)
	{
		if (proc->path)
			free(proc->path);
		i = 0;
		if (proc->argv)
		{
			// while (proc->argv[i])
			// {
			// 	free(proc->argv[i]);
			// 	i++;
			// }
			free(proc->argv);
		}
		tmp = proc;
		proc = proc->next;
		free(tmp);
	}
}
