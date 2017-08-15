/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_expression.c                                :+:      :+:    :+:   */
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

void	ft_expression(t_syntax_tree *tree, t_proc **proc)
{
	int	i;

	if (tree == NULL)
		return ;
	if (!ft_strcmp(tree->type, "arguments"))
	{
		write(1, "args\n", 5);
		i = 0;
		while (tree->tree[i])
		{
			ft_expression(tree->tree[i], proc);
			i++;
		}
	}
	else if (!ft_strcmp(tree->type, "string"))
	{
		write(1, "str\n", 4);
		ft_pre_add_arg(tree, proc);
	}
	else if (!ft_strcmp(tree->type, "redirection"))
	{
		write(1, "redir\n", 6);
		ft_pre_add_redir(tree, proc);
	}
	else if (!ft_strcmp(tree->type, "bquote"))
	{
		write(1, "bquote\n", 7);
		// ft_pre_bquote(tree, proc);
	}
}

void	ft_pre_expression(t_syntax_tree *tree, t_proc **proc)
{
	int		i;

	if (tree == NULL)
		return ;
	write(1, "expr\n", 5);
	if (!(*proc))
	{
		if (!((*proc) = ft_pre_create_proc()))
			return ;
	}
	i = 0;
	while (tree->tree[i])
	{
		ft_expression(tree->tree[i], proc);
		i++;
	}
}
