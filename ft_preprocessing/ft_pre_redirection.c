/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 12:09:22 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/15 12:09:24 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

void	ft_pre_redirection(t_syntax_tree *tree, t_proc **proc)
{
	int	from;
	int	to;

	if (tree->args[0][0] == 'w')
	{
		from = ft_atoi(tree->args[0] + 1);
		printf("redir: %d\n", from);
		if (!ft_strcmp(tree->args[1], "-"))
			(*proc)->dup[from] = -1;
		else if (tree->args[1][0] == '&')
		{
			to = ft_atoi(tree->args[1] + 1);
			(*proc)->dup[from] = to;
		}
	}
}
