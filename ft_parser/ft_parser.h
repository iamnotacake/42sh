/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:33:56 by alischyn          #+#    #+#             */
/*   Updated: 2017/10/01 15:36:06 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PARSER_H
# define __FT_PARSER_H

# include "ft_lexer.h"

# define C031	"\033[0;31m"
# define C032	"\033[0;32m"
# define C033	"\033[0;33m"
# define C034	"\033[0;34m"
# define C035	"\033[0;35m"
# define C036	"\033[0;36m"
# define C037	"\033[0;37m"
# define C131	"\033[1;31m"
# define C132	"\033[1;32m"
# define C133	"\033[1;33m"
# define C134	"\033[1;34m"
# define C135	"\033[1;35m"
# define C136	"\033[1;36m"
# define C137	"\033[1;37m"
# define C0		"\033[0m"

typedef struct	s_syntax_tree
{
	const char				*type;
	struct s_syntax_tree	**tree;
	char					**args;
	int						need_globbing;
}				t_syntax_tree;

void			syntax_tree_free(t_syntax_tree *tree);

void			parser_init_symbol(t_token *tok);

t_syntax_tree	*syntax_arg(void);
t_syntax_tree	*syntax_args(void);
t_syntax_tree	*syntax_redir(void);
t_syntax_tree	*syntax_expr(void);
t_syntax_tree	*syntax_pexpr(void);
t_syntax_tree	*syntax_lexpr(void);
t_syntax_tree	*syntax_exprl(void);
t_syntax_tree	*syntax_bquote(void);

t_syntax_tree	*syntax_tree_new(const char *type);
void			syntax_tree_append(t_syntax_tree *tree,
									t_syntax_tree *tr,
									char *arg);

void			parser_simplify(t_syntax_tree **tree);

#endif
