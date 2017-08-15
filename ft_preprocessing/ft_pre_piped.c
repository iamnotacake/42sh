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

void	ft_pre_proc(t_proc **proc, t_proc **tmp)
{
	if (!(*proc))
		(*proc) = (*tmp);
	else
	{
		(*proc)->next = (*tmp);
		(*tmp)->prev = (*proc);
		(*proc) = (*proc)->next;
	}
}

void	ft_pre_check(t_syntax_tree *tree, t_proc **proc)
{
	int	i;

	if (!ft_strcmp(tree->type, "expression"))
	{
		i = 0;
		while (tree->tree[i])
		{
			ft_expression(tree->tree[i], proc);
			i++;
		}
	}
	else
		printf(""C031"WTF???"C0"\n");
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

void	ft_pre_piped(t_syntax_tree *tree, t_proc **proc)
{
	int		i;
	t_proc	*tmp;
	int		fd;

	if (tree == NULL)
		return ;
	write(1, "piped\n", 6);
	i = 0;
	fd = 0;
	while (tree->tree[i])
	{
		if (!(tmp = ft_pre_create_proc()))
		{
			ft_free_proc((*proc));
			return ;
		}
		ft_pre_proc(proc, &tmp);
		ft_pre_check(tree->tree[i], proc);
		ft_pre_pipe_fd(tree, proc, i, &fd);
		i++;
	}
}
