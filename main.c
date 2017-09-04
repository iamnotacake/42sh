#include <stdio.h>
#include "ft_readline.h"
#include "ft_hash_table.h"
#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_env.h"
#include "ft_free.h"
#include "ft_preprocessing.h"

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

void	go_42(void)
{
	char			*cmd;
	t_syntax_tree	*tree;
	t_token			*tokens;

	while (1)
	{
		if ((cmd = ft_readline("wtf? > ")))
		{
			tokens = token_scan_string(cmd ?: "");
			parser_init_symbol(tokens);
			// glob
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
	// char	*pth;

	(void)argc;
	(void)argv;
	g_history = NULL;
	init_42(envp);
	go_42();
	// char *cmd = ft_readline("Hello! > "); 
	// write(1, "\n", 1);
	// ft_putendl(cmd);
	// const char *cmd = argv[1];
	// t_token *tokens = token_scan_string(cmd);
	// // for (t_token *t = tokens; t; t = t->next)
	// // 	printf(">%s<\n", t->data ?: t->match);
	// // pth = ft_hash_find_command(cmd);
	// parser_init_symbol(tokens);
	// t_syntax_tree *tree = syntax_exprl();
	// parser_simplify(&tree);
	// parser_simplify(&tree);
	// ft_tree_print(tree, 0);
	// ft_preprocessing(tree);
	ft_free();
	return (0);
}
