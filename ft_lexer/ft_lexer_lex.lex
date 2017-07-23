%{
#include "ft_lexer_private.h"

#define PUSH(t, st) token_append(&g_tok, token_new(t, st, yytext))

t_token		*g_tok;
%}

WHITESPACE		[ \t]+
STRING			([^|&;<>()$`\\"' \t\n*?#%]|\\.)+
QUOTE			'[^']*'
QUOTE_EOF		'[^']*
DQUOTE			\"([^\"\\]|\\.)*\"
DQUOTE_EOF		\"([^\"\\]|\\.)*
OP_PIPE			"|"
OP_REDIR		([12&]?>>?)|(<<?)
OP_BRACKET		"("|")"
OP_SEMICOLON	";"
OP_LOGIC		"||"|"&&"

%%

{WHITESPACE}	PUSH(T_WHITESPACE, ST_NONE);
{STRING}		PUSH(T_STRING, ST_NONE);
{QUOTE}			PUSH(T_STRING, ST_QUOTE);
{DQUOTE}		PUSH(T_STRING, ST_DQUOTE);
{QUOTE_EOF}		PUSH(T_STRING, ST_QUOTE_EOF);
{DQUOTE_EOF}	PUSH(T_STRING, ST_DQUOTE_EOF);
{OP_PIPE}		PUSH(T_OP_PIPE, ST_NONE);
{OP_REDIR}		PUSH(T_OP_REDIR, ST_NONE);
{OP_SEMICOLON}	PUSH(T_OP_SEMICOLON, ST_NONE);
{OP_BRACKET}	PUSH(T_OP_BRACKET, *yytext == '(' ? ST_LEFT : ST_RIGHT);
{OP_LOGIC}		PUSH(T_OP_LOGIC, *yytext == '|' ? ST_OR : ST_AND);

%%

t_token			*token_scan_string(const char *string)
{
	g_tok = token_new(T_OP_SEMICOLON, ST_NONE, ";");
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
