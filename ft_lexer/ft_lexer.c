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
	res->match = strdup(match);
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

void			token_free(t_token *tok)
{
	free(tok->match);
	free(tok->data);
	free(tok);
}

void			token_free_all(t_token *tok)
{
	t_token		*next;

	while (tok->prev)
		tok = tok->prev;
	while (tok)
	{
		next = tok->next;
		token_free(tok);
		tok = next;
	}
}
