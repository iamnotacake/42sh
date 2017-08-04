#include "ft_parser_private.h"

#define RETURN_SUCCESS() { return (tree); }
#define RETURN_FAIL() { syntax_tree_free(tree); return (NULL); }

t_syntax_tree 	*syntax_arg(void)
{
	t_syntax_tree	*tree;

	if (parser_accept(T_OP_BQUOTE, ST_LEFT, NULL))
	{
		if (!(tree = syntax_bquote()))
			RETURN_FAIL();
		if (!parser_accept(T_OP_BQUOTE, ST_RIGHT, NULL))
			RETURN_FAIL();
		RETURN_SUCCESS();
	}
	tree = syntax_tree_new("string");
	if (parser_accept(T_STRING, ST_ANY, tree))
		RETURN_SUCCESS();
	RETURN_FAIL();
}

t_syntax_tree	*syntax_args(void)
{
	t_syntax_tree	*tree;
	t_syntax_tree	*elem;

	tree = syntax_tree_new("arguments");
	if (!(elem = syntax_arg()))
		RETURN_FAIL();
	syntax_tree_append(tree, elem, NULL);
	while ((elem = syntax_arg()))
		syntax_tree_append(tree, elem, NULL);
	RETURN_SUCCESS();
}

t_syntax_tree	*syntax_redir(void)
{
	t_syntax_tree	*tree;

	tree = syntax_tree_new("redirection");
	if (parser_accept(T_OP_REDIR, ST_ANY, tree))
	{
		if (parser_accept(T_STRING, ST_ANY, tree))
			RETURN_SUCCESS();
		RETURN_FAIL();
	}
	RETURN_FAIL();
}

t_syntax_tree	*syntax_expr(void)
{
	t_syntax_tree	*tree;
	t_syntax_tree	*elem;

	if (parser_accept(T_OP_BRACKET, ST_LEFT, NULL))
	{
		if (!(tree = syntax_exprl()))
			RETURN_FAIL();
		if (!parser_accept(T_OP_BRACKET, ST_RIGHT, NULL))
			RETURN_FAIL();
		RETURN_SUCCESS();
	}
	tree = syntax_tree_new("expression");
	if (!(elem = syntax_args()))
		RETURN_FAIL();
	syntax_tree_append(tree, elem, NULL);
	while ((elem = syntax_redir()))
		syntax_tree_append(tree, elem, NULL);
	RETURN_SUCCESS();
}

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
		if (!(elem = syntax_lexpr()))
			RETURN_FAIL();
		syntax_tree_append(tree, elem, NULL);
	}
	RETURN_SUCCESS();
}

t_syntax_tree 	*syntax_bquote(void)
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
