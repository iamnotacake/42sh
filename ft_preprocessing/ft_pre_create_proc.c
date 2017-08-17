/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_create_proc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 10:40:14 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/15 10:40:17 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

t_proc	*ft_pre_create_proc(void)
{
	t_proc	*proc;
	int		i;

	i = -1;
	if (!(proc = (t_proc *)malloc(sizeof(t_proc))))
		return (NULL);
	proc->path = NULL;
	proc->argv = NULL;
	while(i++ < 10)
		proc->dup[i] = i;
	proc->pid = 0;
	proc->status = 0;
	proc->prev = NULL;
	proc->next = NULL;
	return (proc);
}

