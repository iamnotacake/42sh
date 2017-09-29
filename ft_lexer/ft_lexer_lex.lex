/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_lex.lex                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:40:53 by mvarga            #+#    #+#             */
/*   Updated: 2017/09/28 17:40:56 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%{
#include "ft_lexer_private.h"

#define PUSH(t, st) \
	token_append(&g_tok, token_new(t, st, \
							t != T_OP_REDIR \
								? yytext \
								: ft_token_redir_seq(yytext)))

static char		*ft_token_redir_seq(const char *op)
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

t_token		*g_tok;
int			g_bquote_count;

%}

WHITESPACE		[ \t]+
STRING			(([^|&;<>()`\\"' \t\n#]|\\.)+)|(&[1-9])
QUOTE			'[^']*'
QUOTE_EOF		'[^']*
DQUOTE			\"([^\"\\]|\\.)*\"
DQUOTE_EOF		\"([^\"\\]|\\.)*
OP_BQUOTE		"`"
OP_PIPE			"|"
OP_REDIR		([1-9&]?>>?)|(<<?)
OP_BRACKET		"("|")"
OP_SEMICOLON	";"
OP_LOGIC		"||"|"&&"

%%

{WHITESPACE}	PUSH(T_WHITESPACE, ST_NONE);
{STRING}		PUSH(T_STRING, ST_NONE);
{OP_BQUOTE}		PUSH(T_OP_BQUOTE, (g_bquote_count++) & 1 ? ST_RIGHT : ST_LEFT);
{QUOTE_EOF}		PUSH(T_STRING, ST_QUOTE_EOF);
{DQUOTE_EOF}	PUSH(T_STRING, ST_DQUOTE_EOF);
{QUOTE}			PUSH(T_STRING, ST_QUOTE);
{DQUOTE}		PUSH(T_STRING, ST_DQUOTE);
{OP_PIPE}		PUSH(T_OP_PIPE, ST_NONE);
{OP_REDIR}		PUSH(T_OP_REDIR, ST_NONE);
{OP_SEMICOLON}	PUSH(T_OP_SEMICOLON, ST_NONE);
{OP_BRACKET}	PUSH(T_OP_BRACKET, *yytext == '(' ? ST_LEFT : ST_RIGHT);
{OP_LOGIC}		PUSH(T_OP_LOGIC, *yytext == '|' ? ST_OR : ST_AND);

%%

t_token			*token_scan_string(const char *string)
{
	g_tok = token_new(T_OP_SEMICOLON, ST_NONE, ";");
	g_bquote_count = 0;
	yy_scan_string(string);
	yylex();
	yy_delete_buffer(YY_CURRENT_BUFFER);
	while (g_tok->prev)
		g_tok = g_tok->prev;
	ft_lexer_post_string(g_tok);
	return (g_tok);
}

void			never_called_shit(void)
{
	input();
	yyunput(0, NULL);
}
