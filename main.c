/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:11:32 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/02 18:11:33 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*g_promt;
t_his		*g_history;
t_hash		**g_table;
t_token		*g_prev_tok;
t_token		*g_curr_sym;
t_token		*g_next_sym;
char		**g_env_g;
int			g_parent;
char		*g_lft;
char		*g_rgt;

static void	init_42(const char *const envp[])
{
	char	*shlvl_str;

	g_parent = 1;
	g_table = ft_hash_table((char **)envp);
	g_env_g = ft_env_init(envp);
	g_history = NULL;
	ft_history_upload();
	g_promt = ft_strdup("wtf?> ");
	ft_env_set(&g_env_g, "SHELL", "42sh");
	if ((shlvl_str = ft_env_get(g_env_g, "SHLVL")))
	{
		shlvl_str = ft_itoa(ft_atoi(shlvl_str) + 1);
		ft_env_set(&g_env_g, "SHLVL", shlvl_str);
		free(shlvl_str);
	}
	else
		ft_env_set(&g_env_g, "SHLVL", "1");
	ft_signals();
}

int			unclosed_quote(t_token *t, int i)
{
	while (t->next)
	{
		i += (t->type == T_OP_BQUOTE);
		t = t->next;
	}
	i += (t->type == T_OP_BQUOTE);
	if (i & 1)
	{
		g_promt = ("bquote> ");
		return (1);
	}
	if (t->subtype == ST_DQUOTE_EOF)
	{
		g_promt = ("dquote> ");
		return (1);
	}
	if (t->subtype == ST_QUOTE_EOF)
	{
		g_promt = ("quote> ");
		return (1);
	}
	return (0);
}

void		ft_find_quotes(t_token **tokens, char **cmd)
{
	char	*oldpromt;

	oldpromt = g_promt;
	while (unclosed_quote(*tokens, 0))
	{
		write(1, "\n", 1);
		free_token_list(*tokens);
		(*cmd) = ft_join_quote(*cmd, ft_readline());
		(*tokens) = token_scan_string((*cmd) ? (*cmd) : "");
	}
	g_promt = oldpromt;
}

/*
**	ft_tree_print(tree, 0);
*/

void		go_42(void)
{
	char			*input;
	t_syntax_tree	*tree;
	t_token			*tokens;

	while (1)
	{
		if ((input = ft_readline()))
		{
			tokens = get_token_list(input ? input : "");
			ft_find_quotes(&tokens, &input);
			parser_init_symbol(tokens);
			tree = syntax_exprl();
			parser_simplify(&tree);
			parser_simplify(&tree);
			write(1, "\n", 1);
			ft_preprocessing(tree);
			ft_free_syntax_tree(tree);
			free_token_list(tokens);
			free(input);
		}
		else
			write(1, "\n", 1);
	}
}

int			main(int argc, const char *const argv[], const char *const envp[])
{
	(void)argc;
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("wtf?: non-interactive mode is not \
supported yet\n", 2);
		return (0);
	}
	init_42(envp);
	go_42();
	ft_free();
	return (0);
}
