/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_post_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:41:28 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 17:43:10 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"

static void		ft_lexer_post_string_extract(t_token *tok)
{
	while (tok)
	{
		if (tok->type == T_STRING)
		{
			if (tok->subtype == ST_NONE)
				tok->data = ft_strdup(tok->match);
			else
				tok->data = ft_strsub(tok->match, 1, ft_strlen(tok->match) - 2);
		}
		tok = tok->next;
	}
}

static void		ft_lexer_join(t_token **tok)
{
	char		*match;
	char		*data;
	t_token		*tmp;

	match = malloc(strlen((*tok)->match) + ft_strlen((*tok)->next->match) + 1);
	ft_strcat(strcpy(match, (*tok)->match), (*tok)->next->match);
	free((*tok)->match);
	(*tok)->match = match;
	data = malloc(strlen((*tok)->data) + ft_strlen((*tok)->next->data) + 1);
	ft_strcat(strcpy(data, (*tok)->data), (*tok)->next->data);
	free((*tok)->data);
	(*tok)->data = data;
	tmp = (*tok)->next->next;
	token_free((*tok)->next);
	(*tok)->next = tmp;
	if (tmp)
		tmp->prev = (*tok);
}

static void		ft_lexer_post_string_join(t_token *tok)
{
	while (tok)
	{
		while (tok->type == T_STRING &&
				tok->next &&
				tok->next->type == T_STRING &&
				tok->next->subtype != ST_DQUOTE_EOF &&
				tok->next->subtype != ST_QUOTE_EOF)
			ft_lexer_join(&tok);
		tok = tok->next;
	}
}

void			ft_lexer_post_string(t_token *tok)
{
	ft_lexer_post_string_extract(tok);
	ft_lexer_resolve_vars(tok);
	ft_lexer_post_string_join(tok);
}
