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

void	ft_pre_add_proc_to_end(t_proc **proc, t_proc **tmp)
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

void	ft_pre_check_next_tree(t_syntax_tree *tree, t_proc **proc)
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
	else if (!ft_strcmp(tree->type, "piped"))
	{
		ft_pre_piped(tree, proc);
	}
	
	else
	{
		printf(""C031"WTF???"C0"\n");
		printf("%s\n", tree->type);
	}
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
	write(1, "piped!\n", 7);
	i = 0;
	fd = 0;
	while (tree->tree[i])
	{
		if (!(tmp = ft_pre_create_proc()))
		{
			ft_free_proc((*proc));
			return ;
		}
		ft_pre_add_proc_to_end(proc, &tmp);
		ft_pre_check_next_tree(tree->tree[i], proc);
		ft_pre_pipe_fd(tree, proc, i, &fd);
		i++;
	}
	// if ((*proc))
	// {
	// 	ft_pre_print_proc(*proc);
	// 	ft_exec(proc);
	// 	ft_free_proc(*proc);
	// }
}
