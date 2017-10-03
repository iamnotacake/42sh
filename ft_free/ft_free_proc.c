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

#include "ft_free.h"

void		ft_free_close_fd(int *fd)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (fd[i] != i && fd[i] > 2)
			close(fd[i]);
		i++;
	}
}

static void	ft_free_one_proc(t_proc **proc)
{
	t_proc	*tmp;
	int		i;

	if ((*proc)->path != NULL)
	{
		free((*proc)->path);
		(*proc)->path = NULL;
	}
	if ((*proc)->argv != NULL)
	{
		i = 0;
		while ((*proc)->argv[i] != NULL)
		{
			free((*proc)->argv[i]);
			(*proc)->argv[i] = NULL;
			i++;
		}
		free((*proc)->argv);
		(*proc)->argv = NULL;
	}
	ft_free_close_fd((*proc)->dup);
	tmp = (*proc);
	free(tmp);
	tmp = NULL;
}

void		ft_free_proc(t_proc **proc)
{
	if ((*proc) == NULL)
		return ;
	while ((*proc)->prev != NULL)
		(*proc) = (*proc)->prev;
	while ((*proc) != NULL)
	{
		ft_free_one_proc(proc);
		(*proc) = (*proc)->next;
	}
}
