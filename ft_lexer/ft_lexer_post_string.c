#include "ft_lexer_private.h"
#include "libft.h"

static void		ft_lexer_post_string_extract(t_token *tok)
{
	while (tok)
	{
		if (tok->type == T_STRING)
		{
			if (tok->subtype == ST_NONE)
				tok->data = strdup(tok->match);
			else
				tok->data = ft_strsub(tok->match, 1, strlen(tok->match) - 2);
		}
		tok = tok->next;
	}
}

static void		ft_lexer_join(t_token **tok)
{
	char		*match;
	char		*data;
	t_token		*tmp;

	match = malloc(strlen((*tok)->match) + strlen((*tok)->next->match) + 1);
	strcat(strcpy(match, (*tok)->match), (*tok)->next->match);
	free((*tok)->match);
	(*tok)->match = match;
	data = malloc(strlen((*tok)->data) + strlen((*tok)->next->data) + 1);
	strcat(strcpy(data, (*tok)->data), (*tok)->next->data);
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
		while (tok->type == T_STRING && tok->next && tok->next->type == T_STRING)
			ft_lexer_join(&tok);
		tok = tok->next;
	}
}

void			ft_lexer_post_string(t_token *tok)
{
	ft_lexer_post_string_extract(tok);
	ft_lexer_post_string_join(tok);
}
