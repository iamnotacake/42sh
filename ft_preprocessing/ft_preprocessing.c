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

void	ft_pre_by_type(t_syntax_tree *tree, t_proc **proc, int *flag)
{
	int		i;
	int		d;

	d = 0;
	if (!tree)
		return ;
	if (!(*proc))	// без этого сегфолт в logic
	{
		if (!((*proc) = ft_pre_create_proc()))
			return ;
	}
	if (!ft_strcmp(tree->type, "expression"))
	{
		if (!(*flag))
		{
			*flag = 1;
			d = 1;
		}
		i = 0;
		printf("expr\n");
		while (tree->tree[i])
		{
			ft_pre_by_type(tree->tree[i], proc, flag);
			i++;
		}
		if (d)
			*flag = 0;
	}
	else if (!ft_strcmp(tree->type, "piped"))
		ft_pre_piped(tree, proc, flag);
	else if (!ft_strcmp(tree->type, "logic"))
		ft_pre_logic(tree, proc, flag);
	else if (!ft_strcmp(tree->type, "list"))
	{
		i = 0;
		while (tree->tree[i])
		{
			if (tree->tree[i])
				ft_pre_by_type(tree->tree[i], proc, flag);
			i++;
		}
	}
	else if (!ft_strcmp(tree->type, "arguments"))
	{
		write(1, "args\n", 5);
		i = 0;
		while (tree->tree[i])
		{
			ft_pre_by_type(tree->tree[i], proc, flag);
			i++;
		}
	}
	else if (!ft_strcmp(tree->type, "string"))
	{
		write(1, "str\n", 4);
		ft_pre_string(tree, proc);
	}
	else if (!ft_strcmp(tree->type, "redirection"))
	{
		write(1, "redir\n", 6);
		ft_pre_redirection(tree, proc);
	}
	else if (!ft_strcmp(tree->type, "bquote"))
	{
		write(1, "bquote\n", 7);
		// ft_pre_bquote(tree, proc, flag);
	}
	if (*proc && !(*flag))
	{
		printf("EXECVE\n");
		ft_pre_print_proc(*proc);
		ft_exec(proc);				// это все под вопросом,
		ft_free_proc(*proc);		// наверное лучше это выполнять в своих логических функциях
		*proc = NULL;
	}
}

void	ft_preprocessing(t_syntax_tree *tree)
{
		t_proc	*proc;
		int		flag;

		proc = NULL;
		flag = 0;
		ft_pre_by_type(tree, &proc, &flag);
}

