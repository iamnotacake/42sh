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

static char		*r_seq(const char *op)
{
	static char	str[3];

	if (op[0] == '&' || ('1' <= op[0] && op[0] <= '9'))
		str[1] = op[0];
	else
		str[1] = '1';
	if (op[1] == '>' && (op[0] == '>' || op[2] == '>'))
		str[0] = 'a';
	else if (op[0] == '>' || op[1] == '>')
		str[0] = 'w';
	else if (op[0] == '<' && op[1] == '<')
	{
		str[1] = '0';
		str[0] = 'h';
	}
	else if (op[0] == '<' || op[1] == '<')
	{
		str[1] = '0';
		str[0] = 'r';
	}
	else
		str[0] = '?';
	str[2] = '\0';
	return (str);
}

size_t		is_whitespace(char *s, t_token **t)
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

size_t		is_string(char *s, t_token **t)
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

size_t		is_quote(char *s, t_token **t)
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

size_t		is_quote_eof(char *s, t_token **t)
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

size_t		is_dquote(char *s, t_token **t)
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

size_t		is_dquote_eof(char *s, t_token **t)
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

size_t		is_bquote(char *s, t_token **t)
{
	if (*s == '`')
	{
		*t = token_new(T_OP_BQUOTE, ST_NONE, "`");
		return (1);
	}
	return (0);
}

size_t		is_pipe(char *s, t_token **t)
{
	if (*s == '|')
	{
		*t = token_new(T_OP_PIPE, ST_NONE, "|");
		return (1);
	}
	return (0);
}

size_t		is_redir(char *s, t_token **t)
{
	size_t	len;
	size_t	rest;
	char	*tmp;

	rest = ft_strlen(s);
	len = 0;
	if (rest > 2 && (ft_isdigit(*s) || *s == '&') && \
											*(s + 1) == '>' && *(s + 2) == '>')
		len = 3;
	else if (rest > 1 && (ft_isdigit(*s) || *s == '&') && *(s + 1) == '>')
		len = 2;
	else if (rest > 1 && *s == '>' && *(s + 1) == '>')
		len = 2;
	else if (rest > 0 && *s == '>')
		len = 1;
	else if (rest > 1 && *s == '<' && *(s + 1) == '<')
		len = 2;
	else if (rest > 0 && *s == '<')
		len = 1;
	if (len)
	{
		tmp = ft_strsub(s, 0, len);
		*t = token_new(T_OP_REDIR, ST_NONE, r_seq(tmp));
		free(tmp);
	}
	return (len);
}

size_t		is_bracket(char *s, t_token **t)
{
	if (*s == '(')
	{
		*t = token_new(T_OP_BRACKET, ST_LEFT, "(");
		return (1);
	}
	else if (*s == ')')
	{
		*t = token_new(T_OP_BRACKET, ST_RIGHT, ")");
		return (1);
	}
	return (0);
}

size_t		is_semicolon(char *s, t_token **t)
{
	if (*s == ';')
	{
		*t = token_new(T_OP_SEMICOLON, ST_NONE, ";");
		return (1);
	}
	return (0);
}

size_t		is_logic(char *s, t_token **t)
{
	if (!ft_strncmp("||", s, 2))
	{
		*t = token_new(T_OP_LOGIC, ST_OR, "||");
		return (2);
	}
	else if (!ft_strncmp("&&", s, 2))
	{
		*t = token_new(T_OP_LOGIC, ST_AND, "&&");
		return (2);
	}
	return (0);
}

t_token		*get_token(char **s)
{
	const lexfunc	filter[] = {is_whitespace, is_string, is_quote, \
		is_quote_eof, is_dquote, is_dquote_eof, is_bquote, is_pipe, is_redir, \
		is_bracket, is_semicolon, is_logic, NULL};
	t_token	*token;
	t_token	*tmp;
	size_t	maxlen;
	size_t	len;
	int		i;

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
