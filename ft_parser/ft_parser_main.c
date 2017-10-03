/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:38:16 by alischyn          #+#    #+#             */
/*   Updated: 2017/10/01 15:40:45 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"
#include "ft_free.h"

#define RETURN_SUCCESS() { return (tree); }
#define RETURN_FAIL() { ft_free_syntax_tree(tree); return (NULL); }

t_syntax_tree	*syntax_pexpr(void)
{
	t_syntax_tree	*tree;
	t_syntax_tree	*elem;

	tree = syntax_tree_new("piped");
	if (!(elem = syntax_expr()))
		RETURN_FAIL();
	syntax_tree_append(tree, elem, NULL);
	while (parser_accept(T_OP_PIPE, ST_ANY, NULL))
	{
		if (!(elem = syntax_expr()))
			RETURN_FAIL();
		syntax_tree_append(tree, elem, NULL);
	}
	RETURN_SUCCESS();
}

t_syntax_tree	*syntax_lexpr(void)
{
	t_syntax_tree	*tree;
	t_syntax_tree	*elem;

	tree = syntax_tree_new("logic");
	if (!(elem = syntax_pexpr()))
		RETURN_FAIL();
	syntax_tree_append(tree, elem, NULL);
	while (parser_accept(T_OP_LOGIC, ST_ANY, tree))
	{
		if (!(elem = syntax_pexpr()))
			RETURN_FAIL();
		syntax_tree_append(tree, elem, NULL);
	}
	RETURN_SUCCESS();
}

t_syntax_tree	*syntax_exprl(void)
{
	t_syntax_tree	*tree;
	t_syntax_tree	*elem;

	tree = syntax_tree_new("list");
	while (parser_accept(T_OP_SEMICOLON, ST_ANY, NULL))
		;
	if (!(elem = syntax_lexpr()))
		RETURN_FAIL();
	syntax_tree_append(tree, elem, NULL);
	while (parser_accept(T_OP_SEMICOLON, ST_ANY, NULL))
	{
		while (parser_accept(T_OP_SEMICOLON, ST_ANY, NULL))
			;
		if ((elem = syntax_lexpr()))
			syntax_tree_append(tree, elem, NULL);
	}
	RETURN_SUCCESS();
}

t_syntax_tree	*syntax_bquote(void)
{
	t_syntax_tree	*tree;
	t_syntax_tree	*elem;

	tree = syntax_tree_new("bquote");
	while (parser_accept(T_OP_SEMICOLON, ST_ANY, NULL))
		;
	if (!(elem = syntax_lexpr()))
		RETURN_FAIL();
	syntax_tree_append(tree, elem, NULL);
	while (parser_accept(T_OP_SEMICOLON, ST_ANY, NULL))
	{
		while (parser_accept(T_OP_SEMICOLON, ST_ANY, NULL))
			;
		if (!(elem = syntax_lexpr()))
			RETURN_FAIL();
		syntax_tree_append(tree, elem, NULL);
	}
	RETURN_SUCCESS();
}
