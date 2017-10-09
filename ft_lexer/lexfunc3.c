/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexfunc3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:21 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/09 16:38:21 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"

static char	*r_seq(const char *op)
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
	else if (rest > 1 && *s == '<' && *(s + 1) == '<')
		len = 2;
	else if (rest > 0 && (*s == '>' || *s == '<'))
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
