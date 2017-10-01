/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:33:12 by alischyn          #+#    #+#             */
/*   Updated: 2017/10/01 15:40:45 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PARSER_PRIVATE_H
# define __FT_PARSER_PRIVATE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "ft_lexer.h"
# include "ft_parser.h"

extern t_token	*g_prev_tok;
extern t_token	*g_curr_sym;
extern t_token	*g_next_sym;

void			parser_next_symbol(void);
void			parser_prev_symbol(void);
int				parser_accept(t_token_type type,
								t_token_subtype subtype,
								t_syntax_tree *tree);

t_syntax_tree	*syntax_arg(void);
t_syntax_tree	*syntax_args(void);
t_syntax_tree	*syntax_redir(void);
t_syntax_tree	*syntax_expr(void);
t_syntax_tree	*syntax_pexpr(void);
t_syntax_tree	*syntax_lexpr(void);
t_syntax_tree	*syntax_exprl(void);
t_syntax_tree	*syntax_bquote(void);

#endif
