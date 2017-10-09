/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:17:48 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 17:39:29 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"

t_token			*token_new(t_token_type type,
							t_token_subtype subtype,
							const char *match)
{
	t_token		*res;

	res = malloc(sizeof(t_token));
	res->prev = NULL;
	res->next = NULL;
	res->type = type;
	res->subtype = subtype;
	res->match = ft_strdup(match);
	res->data = NULL;
	return (res);
}

t_token			*token_append(t_token **tok, t_token *next)
{
	if (*tok)
	{
		(*tok)->next = next;
		next->prev = (*tok);
	}
	*tok = next;
	return (next);
}
