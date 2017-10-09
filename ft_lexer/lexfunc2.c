/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexfunc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:15 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/09 16:38:15 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"

size_t	is_dquote(char *s, t_token **t)
{
	size_t	len;
	char	*tmp;

	len = 0;
	if (*s == '\"')
	{
		len = 1;
		while (*(s + len) && \
			((*(s + len) != '\"') || (len && *(s + len - 1) == '\\')))
			len++;
	}
	if (len && *(s + len) == '\"')
	{
		len++;
		tmp = ft_strsub(s, 0, len);
		*t = token_new(T_STRING, ST_DQUOTE, tmp);
		free(tmp);
		return (len);
	}
	return (0);
}

size_t	is_dquote_eof(char *s, t_token **t)
{
	size_t	len;
	char	*tmp;

	len = 0;
	if (*s == '\"')
	{
		len = 1;
		while (*(s + len))
		{
			if (*(s + len) == '\"')
			{
				len = 0;
				break ;
			}
			len++;
		}
	}
	if (len)
	{
		tmp = ft_strsub(s, 0, len);
		*t = token_new(T_STRING, ST_DQUOTE_EOF, tmp);
		free(tmp);
	}
	return (len);
}

size_t	is_bquote(char *s, t_token **t)
{
	if (*s == '`')
	{
		*t = token_new(T_OP_BQUOTE, ST_NONE, "`");
		return (1);
	}
	return (0);
}

size_t	is_pipe(char *s, t_token **t)
{
	if (*s == '|')
	{
		*t = token_new(T_OP_PIPE, ST_NONE, "|");
		return (1);
	}
	return (0);
}
