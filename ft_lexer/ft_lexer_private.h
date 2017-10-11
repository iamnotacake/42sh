/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:44:39 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 17:44:43 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LEXER_PRIVATE_H
# define __FT_LEXER_PRIVATE_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include "ft_lexer.h"

t_token			*token_new(t_token_type type, t_token_subtype subtype, \
															const char *match);
t_token			*token_append(t_token **tok, t_token *next);

void			ft_lexer_post_string(t_token *toks);
void			ft_lexer_resolve_vars(t_token *toks);

size_t			is_whitespace(char *s, t_token **token);
size_t			is_string(char *s, t_token **token);
size_t			is_quote(char *s, t_token **token);
size_t			is_quote_eof(char *s, t_token **token);
size_t			is_dquote(char *s, t_token **token);
size_t			is_dquote_eof(char *s, t_token **token);
size_t			is_bquote(char *s, t_token **token);
size_t			is_pipe(char *s, t_token **token);
size_t			is_redir(char *s, t_token **token);
size_t			is_bracket(char *s, t_token **token);
size_t			is_semicolon(char *s, t_token **token);
size_t			is_logic(char *s, t_token **token);

#endif
