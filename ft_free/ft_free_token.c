/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:57:31 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/09 16:57:31 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	free_token(t_token *token)
{
	free(token->match);
	free(token->data);
	free(token);
}

void	free_token_list(t_token *token)
{
	t_token		*next;

	while (token->prev)
		token = token->prev;
	while (token)
	{
		next = token->next;
		free_token(token);
		token = next;
	}
}
