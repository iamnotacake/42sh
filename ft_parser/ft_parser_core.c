/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:51:15 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/03 16:51:18 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"

extern t_token	*g_prev_tok;
extern t_token	*g_curr_sym;
extern t_token	*g_next_sym;

void			parser_init_symbol(t_token *tok)
{
	g_prev_tok = NULL;
	g_curr_sym = tok;
	g_next_sym = tok->next;
}

void			parser_next_symbol(void)
{
	g_prev_tok = g_curr_sym;
	g_curr_sym = g_next_sym;
	g_next_sym = g_curr_sym ? g_curr_sym->next : NULL;
}

void			parser_prev_symbol(void)
{
	g_next_sym = g_curr_sym;
	g_curr_sym = g_next_sym ? g_next_sym->prev : NULL;
	g_prev_tok = g_curr_sym ? g_curr_sym->prev : NULL;
}

int				parser_accept(t_token_type type,
								t_token_subtype subtype,
								t_syntax_tree *tree)
{
	if (g_curr_sym && g_curr_sym->type == T_WHITESPACE)
		parser_next_symbol();
	if (g_curr_sym && g_curr_sym->type == type &&
		(subtype == ST_ANY || g_curr_sym->subtype == subtype))
	{
		if (tree)
		{
			syntax_tree_append(tree, NULL,
					strdup(g_curr_sym->data ? g_curr_sym->data : \
														g_curr_sym->match));
			tree->need_globbing = g_curr_sym->type == T_STRING &&
				g_curr_sym->subtype == ST_NONE;
		}
		parser_next_symbol();
		return (1);
	}
	return (0);
}

/*
** void			ft_tree_print(t_syntax_tree *tree, int level)
** {
** 	for (int i = 0; i < level; i++) printf(". ");
** 	printf("<"C137"%s"C0">\n", tree ? tree->type : "NULL");
** 	if (!tree)
** 		return ;
** 	for (int i = 0; tree->tree[i]; i++)
** 		ft_tree_print(tree->tree[i], level + 1);
** 	for (int i = 0; tree->args[i]; i++)
** 	{
** 		for (int i = 0; i < level; i++) printf(". ");
** 		printf("%s"C036"args"C0"["C032"%d"C0"]: "C033"%s"C0"\n",
** 				tree->args[i + 1] ? "┣ " : "┗ ", i, tree->args[i]);
** 	}
** }
*/
