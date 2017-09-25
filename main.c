#include <stdio.h>
#include <string.h>
#include "ft_readline.h"
#include "ft_hash_table.h"
#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_env.h"
#include "ft_free.h"
#include "ft_preprocessing.h"

char	*g_promt;
t_his	*g_history;
t_hash	*g_table;
t_token	*g_prev_tok;
t_token	*g_curr_sym;
t_token	*g_next_sym;
char	**g_env_g;
char	**g_env_l;

// void	ft_tree_print(t_syntax_tree *tree, int level);

void	init_42(const char *const envp[])
{
	g_table = NULL;
	ft_hash_table(envp);
	ft_env_init(&g_env_g, envp);
	g_env_l = malloc(sizeof(char *) * 2);
	g_env_l[0] = NULL;
	// ft_print_table();
	// parser_init();
}

int 	unclosed_quote(t_token *t)
{
	while (t->next)
		t = t->next;
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

char	*ft_join_quote(char *a, char *b)
{
	char *res;

	res = malloc(strlen(a) + 1 + strlen(b ?: "") + 1);
	strcpy(res, a);
	strcat(res, "\n");
	strcat(res, b ?: "");
	free(a);
	free(b);
	return (res);
}

void	ft_find_quotes(t_token **tokens, char **cmd)
{
	char	*oldpromt;

	oldpromt = g_promt;
	while (unclosed_quote(*tokens))
	{
		write(1, "\n", 1);
		token_free_all(*tokens);
		(*cmd) = ft_join_quote(*cmd, ft_readline());
		(*tokens) = token_scan_string((*cmd) ?: "");
	}
	g_promt = oldpromt;
}

void	go_42(void)
{
	char			*cmd;
	t_syntax_tree	*tree;
	t_token			*tokens;

	while (1)
	{
		if ((cmd = ft_readline()))
		{
			tokens = token_scan_string(cmd ?: "");
			ft_find_quotes(&tokens, &cmd);
			parser_init_symbol(tokens);
			tree = syntax_exprl();
			parser_simplify(&tree);
			parser_simplify(&tree);
			write(1, "\n", 1);
			ft_tree_print(tree, 0);
			ft_preprocessing(tree);
			ft_free_syntax_tree(tree);
			token_free_all(tokens);
			free(cmd);
		}
		else
			write(1, "\n", 1);
	}
}

int		main(int argc, const char *const argv[], const char *const envp[])
{
	(void)argc;
	(void)argv;
	g_promt = ft_strdup("wtf ?> ");
	g_history = NULL;
	// ft_signals();
	init_42(envp);
	go_42();
	ft_free();
	return (0);
}
