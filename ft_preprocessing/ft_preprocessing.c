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

void	ft_preprocessing(t_syntax_tree *tree)
{
	int		i;
	t_proc	*proc;

	proc = NULL;
	if (!ft_strcmp(tree->type, "expression"))
		ft_pre_expression(tree, &proc);
	else if (!ft_strcmp(tree->type, "piped"))
		ft_pre_piped(tree, &proc);
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
	if (proc)
	{
		ft_pre_print_proc(proc);
		ft_free_proc(proc);
	}
}

