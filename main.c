#include <stdio.h>
#include "ft_readline.h"
#include "ft_hash_table.h"
#include "ft_lexer.h"
#include "ft_parser.h"

void	init_42(const char *const envp[])
{
	/* g_table = NULL; */
	/* ft_hash_table(envp); */
	parser_init();
}

int		main(int argc, const char *const argv[], const char *const envp[])
{
	char	*pth;

	init_42(envp);
	/* char *cmd = ft_readline("Hello! > "); */
	/* write(1, "\n", 1); */
	/* t_token *tokens = token_scan_string(cmd); */
	/* for (t_token *t = tokens; t; t = t->next) */
		/* printf(">%s<\n", t->data ?: t->match); */
	/* pth = ft_hash_find_command(cmd); */
	/* ft_hash_free_table(); */
	return (0);
}
