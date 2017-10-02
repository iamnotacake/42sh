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

void	ft_pre_logic_while(t_syntax_tree *tree, t_proc **proc, int *lock)
{
	static int	stat = 0;
	static char	*logic;
	int			i;

	logic = NULL;
	i = 0;
	while (tree->tree[i])
	{
		if ((ft_strequ(logic, "&&") && !stat) ||
			(ft_strequ(logic, "||") && stat) || !i)
		{
			ft_pre_by_type(tree->tree[i], proc, lock);
			if (*proc)
			{
				stat = ft_exec(proc);
			}
		}
		if (tree->args[i])
			logic = tree->args[i];
		ft_free_proc(proc);
		(*proc) = NULL;
		i++;
	}
}

void	ft_pre_logic(t_syntax_tree *tree, t_proc **proc, int *lock)
{
	int			d;

	d = 0;
	if (tree == NULL)
		return ;
	if (!(*lock))
	{
		*lock = 1;
		d = 1;
	}
	ft_pre_logic_while(tree, proc, lock);
	if (d)
		*lock = 0;
}
