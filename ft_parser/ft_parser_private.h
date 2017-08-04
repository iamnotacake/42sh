#ifndef __FT_PARSER_PRIVATE_H
# define  __FT_PARSER_PRIVATE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "ft_lexer.h"
# include "ft_parser.h"

t_token			*g_prev_tok;
t_token			*g_curr_sym;
t_token			*g_next_sym;

t_syntax_tree 	*syntax_tree_new(const char *type);
void 			syntax_tree_append(t_syntax_tree *tree,
									t_syntax_tree *tr,
									char *arg);

void 			parser_next_symbol(void);
void 			parser_prev_symbol(void);
int				parser_accept(t_token_type type,
								t_token_subtype subtype,
								t_syntax_tree *tree);

#endif
