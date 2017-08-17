/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:31:16 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/16 11:31:18 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

void	ft_pre_logic(t_syntax_tree *tree, t_proc **proc, int *flag)
{
	int		i;
	char	**logic;
	int		result;

	if (tree == NULL)
		return ;
	write(1, "logic\n", 6);
	i = 0;
	logic = tree->args;
	while (tree->tree[i])
	{
		ft_pre_by_type(tree->tree[i], proc, flag);
		ft_pre_print_proc(*proc);
		if (logic[i])
		{
			result = ft_exec(proc);
			if ((!ft_strcmp(logic[i], "&&") && result) ||
				(!ft_strcmp(logic[i], "||") && !result))
			{
				printf("NOT TRUE!\n");
				ft_free_proc((*proc));
				(*proc) = NULL;
				return ;
			}
		}
		ft_free_proc((*proc));
		(*proc) = NULL;
		i++;
	}
}
