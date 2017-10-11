/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:08 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/09 16:38:09 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"

size_t	is_whitespace(char *s, t_token **t)
{
	size_t	len;
	char	*tmp;

	len = 0;
	if (ft_isspace(*s))
	{
		while (*(s + len) && ft_isspace(*(s + len)))
			len++;
		tmp = ft_strnew(len);
		ft_memset(tmp, ' ', len);
		*t = token_new(T_WHITESPACE, ST_NONE, tmp);
		free(tmp);
	}
	return (len);
}

size_t	is_string(char *s, t_token **t)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (!ft_strchr("|&;<>()`\\\"' \t\n#", *(s + len)) || \
			(*(s + len) == '\\' && *(s + len + 1) != '\n') || \
			(len && *(s + len - 1) == '\\'))
		len++;
	if (!len && *s == '&' && ft_isdigit(*(s + 1)))
		len = 2;
	if (len)
	{
		tmp = ft_strsub(s, 0, len);
		*t = token_new(T_STRING, ST_NONE, tmp);
		free(tmp);
	}
	return (len);
}

size_t	is_quote(char *s, t_token **t)
{
	size_t	len;
	char	*tmp;

	len = 0;
	if (*s == '\'')
	{
		len = 1;
		while (*(s + len) && *(s + len) != '\'')
			len++;
	}
	if (len && *(s + len) == '\'')
	{
		len++;
		tmp = ft_strsub(s, 0, len);
		*t = token_new(T_STRING, ST_QUOTE, tmp);
		free(tmp);
		return (len);
	}
	return (0);
}

size_t	is_quote_eof(char *s, t_token **t)
{
	size_t	len;
	char	*tmp;

	len = 0;
	if (*s == '\'')
	{
		len = 1;
		while (*(s + len))
		{
			if (*(s + len) == '\'')
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
		*t = token_new(T_STRING, ST_QUOTE_EOF, tmp);
		free(tmp);
	}
	return (len);
}
