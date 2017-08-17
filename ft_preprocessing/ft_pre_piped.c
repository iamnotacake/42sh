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

	// if (!(*proc)->argv)
	// {
		if (!(tmp = ft_pre_create_proc()))
		{
			ft_free_proc((*proc));
			return ;
		}
	// 	(*proc)->next = tmp;
	// 	tmp->prev = (*proc);
	// 	(*proc) = (*proc)->next;
	// }
	// else
	// {
		(*proc)->next = tmp;
		tmp->prev = (*proc);
		(*proc) = (*proc)->next;
	// }
}

void	ft_pre_pipe_fd(t_syntax_tree *tree, t_proc **proc, int i, int *fd)
{
	int	p[2];

	if (i == 0)
	{
		pipe(p);
		(*proc)->dup[1] = p[1];
		(*fd) = p[0];
	}
	else if (tree->tree[i + 1])
	{
		pipe(p);
		(*proc)->dup[0] = (*fd);
		(*proc)->dup[1] = p[1];
		(*fd) = p[0];
	}
	else if (!tree->tree[i + 1])
	{
		(*proc)->dup[0] = (*fd);
	}
}

void	ft_pre_piped(t_syntax_tree *tree, t_proc **proc, int *flag)
{
	int		i;
	// t_proc	*tmp;
	int		fd;

	if (tree == NULL)
		return ;
	write(1, "piped!\n", 7);
	i = 0;
	fd = 0;
	*flag = 1;
	while (tree->tree[i])
	{
		// if (!(tmp = ft_pre_create_proc()))
		// {
		// 	ft_free_proc((*proc));
		// 	return ;
		// }
		// ft_pre_add_proc_to_end(proc);
		ft_pre_by_type(tree->tree[i], proc, flag);
		ft_pre_pipe_fd(tree, proc, i, &fd);
		if (tree->tree[i + 1])
		{
			ft_pre_add_proc_to_end(proc);
		}
		i++;
	}
	*flag = 0;
}
