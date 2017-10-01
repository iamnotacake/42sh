/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:36:50 by alischyn          #+#    #+#             */
/*   Updated: 2017/10/01 15:37:58 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"

t_syntax_tree	*syntax_tree_new(const char *type)
{
	t_syntax_tree	*tree;

	tree = malloc(sizeof(t_syntax_tree));
	tree->type = type;
	tree->tree = malloc(sizeof(void *));
	tree->tree[0] = NULL;
	tree->args = malloc(sizeof(void *));
	tree->args[0] = NULL;
	return (tree);
}

void			syntax_tree_free(t_syntax_tree *tree)
{
	int			i;

	if (tree != NULL)
		return ;
	i = 0;
	while (tree->tree[i])
	{
		syntax_tree_free(tree->tree[i]);
		i += 1;
	}
	free(tree->tree);
	i = 0;
	if (tree->args)
	{
		while (tree->args[i])
		{
			free(tree->args[i]);
			parser_prev_symbol();
			i += 1;
		}
		free(tree->args);
	}
	free(tree);
}

void			syntax_tree_append(t_syntax_tree *tree,
									t_syntax_tree *tr,
									char *arg)
{
	int		i;

	i = 0;
	if (tr)
	{
		while (tree->tree[i])
			i += 1;
		tree->tree = realloc(tree->tree, sizeof(void *) * (i + 2));
		tree->tree[i] = tr;
		tree->tree[i + 1] = NULL;
	}
	i = 0;
	if (arg)
	{
		while (tree->args[i])
			i += 1;
		tree->args = realloc(tree->args, sizeof(void *) * (i + 2));
		tree->args[i] = arg;
		tree->args[i + 1] = NULL;
	}
}
