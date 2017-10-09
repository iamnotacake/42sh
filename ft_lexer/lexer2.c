/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:22:22 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/04 15:22:23 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"

t_token		*get_token(char **s)
{
	const t_lexfunc	filter[] = {is_whitespace, is_string, is_quote, \
		is_quote_eof, is_dquote, is_dquote_eof, is_bquote, is_pipe, is_redir, \
		is_bracket, is_semicolon, is_logic, NULL};
	t_token			*token;
	t_token			*tmp;
	size_t			maxlen;
	size_t			len;
	int				i;

	token = NULL;
	maxlen = 0;
	while (**s && !token)
	{
		i = 0;
		while (**s && filter[i])
		{
			tmp = NULL;
			len = filter[i++](*s, &tmp);
			if (len > maxlen)
			{
				if (token)
					token_free(token);
				token = tmp;
				maxlen = len;
			}
		}
		*s += (maxlen) ? maxlen : 1;
	}
	return (token);
}

t_token		*get_token_list(char *str)
{
	t_token	*list;
	t_token	*last;
	t_token	*new;
	char	bquote;
	char	*s;

	list = token_new(T_OP_SEMICOLON, ST_NONE, ";");
	last = list;
	s = str;
	bquote = 0;
	while ((new = get_token(&s)))
	{
		if (new->type == T_OP_BQUOTE)
			new->subtype = (bquote++) & 1 ? ST_RIGHT : ST_LEFT;
		ft_lexer_post_string(new);
		last->next = new;
		new->prev = last;
		last = new;
	}
	return (list);
}
