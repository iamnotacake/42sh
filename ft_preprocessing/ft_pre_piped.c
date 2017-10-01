/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_piped.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:12:04 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/15 13:12:06 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

void	ft_pre_add_proc_to_end(t_proc **proc)
{
	t_proc	*tmp;

	if (!(*proc))
		return ;
	if (!(tmp = ft_pre_create_proc()))
	{
		ft_free_proc((*proc));
		return ;
	}
	(*proc)->next = tmp;
	tmp->prev = (*proc);
	(*proc) = (*proc)->next;
}

void	ft_pre_short(t_proc **proc, int fd)
{
	if ((*proc)->dup[0] != 0 && (*proc)->dup[0] > 2)
		close((*proc)->dup[0]);
	(*proc)->dup[0] = fd;
}

void	ft_pre_pipe_fd(t_syntax_tree *tree, t_proc **proc, int i, int *fd)
{
	int	p[2];

	if (i == 0)
	{
		pipe(p);
		if ((*proc)->dup[1] != 1 && (*proc)->dup[1] > 2)
			close((*proc)->dup[1]);
		(*proc)->dup[1] = p[1];
		(*fd) = p[0];
	}
	else if (tree->tree[i + 1])
	{
		pipe(p);
		if ((*proc)->dup[0] != 0 && (*proc)->dup[0] > 2)
			close((*proc)->dup[0]);
		if ((*proc)->dup[1] != 1 && (*proc)->dup[1] > 2)
			close((*proc)->dup[1]);
		(*proc)->dup[0] = (*fd);
		(*proc)->dup[1] = p[1];
		(*fd) = p[0];
	}
	else if (!tree->tree[i + 1])
		ft_pre_short(proc, *fd);
}

void	ft_pre_fill_list(t_syntax_tree *tree, t_proc **proc, int *lock)
{
	int		i;
	int		fd;

	i = 0;
	fd = 0;
	while (tree->tree[i])
	{
		ft_pre_pipe_fd(tree, proc, i, &fd);
		ft_pre_by_type(tree->tree[i], proc, lock);
		if (i > 0 && !(*proc))
		{
			if (fd != 0)
				close(fd);
			return ;
		}
		// ft_pre_pipe_fd(tree, proc, i, &fd);
		if (tree->tree[i + 1])
			ft_pre_add_proc_to_end(proc);
		i++;
	}
}

void	ft_pre_piped(t_syntax_tree *tree, t_proc **proc, int *lock)
{
	int		d;

	if (tree == NULL)
		return ;
	d = 0;
	if (!(*lock))
	{
		*lock = 1;
		d = 1;
	}
	ft_pre_fill_list(tree, proc, lock);
	if (d)
		*lock = 0;
}
