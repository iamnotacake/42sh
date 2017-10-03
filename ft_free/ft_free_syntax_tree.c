/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_syntax_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 15:02:23 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/08 15:02:25 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"

void	ft_free_syntax_tree(t_syntax_tree *tree)
{
	int		i;

	if (!tree)
		return ;
	i = 0;
	while (tree->tree && tree->tree[i])
	{
		ft_free_syntax_tree(tree->tree[i]);
		i++;
	}
	free(tree->tree);
	i = 0;
	while (tree->args && tree->args[i])
	{
		free(tree->args[i]);
		parser_prev_symbol();
		i++;
	}
	free(tree->args);
	free(tree);
}
