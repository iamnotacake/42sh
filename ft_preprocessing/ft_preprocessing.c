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
#include "ft_parser.h"
#include "ft_exec.h"
#include "ft_lexer.h"
#include "ft_free.h"

#include <stdio.h>

// t_proc	*ft_create_proc(void)
// {
// 	t_proc	*proc;
// 	int		i;

// 	i = -1;
// 	if (!(proc = (t_proc *)malloc(sizeof(t_proc))))
// 		return (NULL);
// 	proc->path = NULL;
// 	proc->argv = NULL;
// 	while(i++ < 10)
// 		proc->dup[i] = i;
// 	proc->pid = 0;
// 	proc->status = 0;
// 	proc->prev = NULL;
// 	proc->next = NULL;
// 	return (proc);
// }

// void	ft_pre_add_arg(t_syntax_tree *tree, t_proc **proc)
// {
// 	if (tree == NULL)
// 		return ;
// 	if (!(*proc)->argv)
// 	{

// 	}
// }

// void	ft_expression(t_syntax_tree *tree, t_proc **proc, int *level)
// {
// 	int	i;

// 	if (tree == NULL)
// 		return ;
// 	if (!ft_strcmp(tree->type, "arguments"))
// 	{
// 		write(1, "args\n", 5);
// 		i = 0;
// 		while (tree->tree[i])
// 		{
// 			(*level)++;
// 			ft_expression(tree->tree[i], proc, level);
// 			(*level)--;
// 			i++;
// 		}
// 	}
// 	else if (!ft_strcmp(tree->type, "string"))
// 	{
// 		write(1, "str\n", 4);
// 		ft_pre_add_arg(tree, proc);
// 	}
// 	else if (!ft_strcmp(tree->type, "redirection"))
// 	{
// 		write(1, "redir\n", 6);
// 	}
// 	printf("%d\n", *level);
// }

void	ft_preprocessing(t_syntax_tree *tree)
{
	int		i;
	// t_proc	*proc;
	// int		level;

	// level = 0;
	// if (tree == NULL)
	// 	return ;
	if (!ft_strcmp(tree->type, "expression"))
	{
		ft_pre_expression(tree);
		// write(1, "expr\n", 5);
		// if (!(proc = ft_create_proc()))
		// 	return ;
		// i = 0;
		// while (tree->tree[i])
		// {
		// 	ft_expression(tree->tree[i], &proc, &level);
		// 	i++;
		// }
		// ft_free_proc(proc);
	}
	else if (!ft_strcmp(tree->type, "list"))
	{
		i = 0;
		while (tree->tree[i])
		{
			if (tree->tree[i])
				ft_preprocessing(tree->tree[i]);
			i++;
		}
	}
}

