/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 09:41:43 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/05 09:41:45 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

void	ft_pre_expression(t_syntax_tree *tree, t_proc **proc, int *lock)
{
	int	d;
	int	i;

	d = 0;
	i = 0;
	if (!(*lock))
	{
		*lock = 1;
		d = 1;
	}
	while (tree->tree[i])
	{
		ft_pre_by_type(tree->tree[i], proc, lock);
		i++;
	}
	if (d)
		*lock = 0;
}

void	ft_pre_list(t_syntax_tree *tree, t_proc **proc, int *lock)
{
	int	d;
	int	i;

	d = 0;
	i = 0;
	if ((*lock))
	{
		*lock = 0;
		d = 1;
	}
	while (tree->tree[i])
	{
		if (tree->tree[i])
			ft_pre_by_type(tree->tree[i], proc, lock);
		i++;
	}
	if (d)
		*lock = 1;
}

void	ft_pre_arguments(t_syntax_tree *tree, t_proc **proc, int *lock)
{
	int	i;

	i = 0;
	i = 0;
	while (tree->tree[i])
	{
		ft_pre_by_type(tree->tree[i], proc, lock);
		i++;
	}
}

void	ft_pre_by_type(t_syntax_tree *tree, t_proc **proc, int *lock)
{
	if (!tree)
		return ;
	if (!(*proc))
	{
		if (!((*proc) = ft_pre_create_proc()))
			return ;
	}
	if (!ft_strcmp(tree->type, "expression"))
		ft_pre_expression(tree, proc, lock);
	else if (!ft_strcmp(tree->type, "piped"))
		ft_pre_piped(tree, proc, lock);
	else if (!ft_strcmp(tree->type, "logic"))
		ft_pre_logic(tree, proc, lock);
	else if (!ft_strcmp(tree->type, "list"))
		ft_pre_list(tree, proc, lock);
	else if (!ft_strcmp(tree->type, "arguments"))
		ft_pre_arguments(tree, proc, lock);
	else if (!ft_strcmp(tree->type, "string"))
		ft_pre_string(tree, proc);
	else if (!ft_strcmp(tree->type, "redirection"))
		ft_pre_redirection(tree, proc);
	else if (!ft_strcmp(tree->type, "bquote"))
		ft_pre_bquote(tree, proc, lock);
	if (*proc && !(*lock))
		ft_pre_exec(proc);
}

void	ft_preprocessing(t_syntax_tree *tree)
{
	t_proc	*proc;
	int		lock;

	proc = NULL;
	lock = 0;
	ft_pre_by_type(tree, &proc, &lock);
}
