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
#include "ft_free.h"

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

static void		append_tree_arr(t_syntax_tree ***tree, t_syntax_tree *new_elem)
{
	t_syntax_tree	**new;
	int				i;

	i = 0;
	while ((*tree)[i])
		i++;
	new = malloc(sizeof(t_syntax_tree *) * (i + 2));
	i = 0;
	while ((*tree)[i])
	{
		new[i] = (*tree)[i];
		i++;
	}
	new[i] = new_elem;
	new[i + 1] = NULL;
	free(*tree);
	(*tree) = new;
}

static void		append_arg_arr(char ***args, char *new_elem)
{
	char	**new;
	int		i;

	i = 0;
	while ((*args)[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while ((*args)[i])
	{
		new[i] = (*args)[i];
		i++;
	}
	new[i] = new_elem;
	new[i + 1] = NULL;
	free(*args);
	(*args) = new;
}

void			syntax_tree_append(t_syntax_tree *tree, \
										t_syntax_tree *subtree, char *arg)
{
	if (subtree)
		append_tree_arr(&(tree->tree), subtree);
	if (arg)
		append_arg_arr(&(tree->args), arg);
}
