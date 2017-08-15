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

t_token			*g_prev_tok;
t_token			*g_curr_sym;
t_token			*g_next_sym;

void			prev_symbol(void)
{
	g_next_sym = g_curr_sym;
	g_curr_sym = g_next_sym ? g_next_sym->prev : NULL;
	g_prev_tok = g_curr_sym ? g_curr_sym->prev : NULL;
}

void	ft_free_syntax_tree(t_syntax_tree *tree)
{
	int			i;

	if (!tree)
		return ;
	i = 0;
	while (tree->tree[i])
	{
		ft_free_syntax_tree(tree->tree[i]);
		i += 1;
	}
	free(tree->tree);
	i = 0;
	while (tree->args[i])
	{
		free(tree->args[i]);
		prev_symbol();
		i += 1;
	}
	free(tree->args);
	free(tree);
}