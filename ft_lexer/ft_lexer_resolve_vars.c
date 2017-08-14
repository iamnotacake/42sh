#include "ft_env.h"
#include "ft_lexer_private.h"

static char	const	*ft_get_var_content(const char *var, int len)
{
	char const	*res;
	static char	tmp[64];

	bzero(tmp, sizeof(tmp));
	strncpy(tmp, var, len);
	if (var[0] == '$')
	{
		sprintf(tmp, "%d", getpid());
		return (tmp);
	}
	res = ft_env_get(g_env_l, tmp);
	if (res)
		return (res);
	res = ft_env_get(g_env_g, tmp);
	if (res)
		return (res);
	return "";
}

static int			ft_xxyy(t_token *tok, int i)
{
	int				j;
	char			*tmp;

	j = 1;
	while (isalpha(tok->data[i + j]) || (j > 1 && isalnum(tok->data[i + j])))
		j += 1;
	if (j > 1 || (tok->data[i + j] == '$' && (j += 1)))
	{
		asprintf(&tmp, "%.*s%s%s",
				i, tok->data,
				ft_get_var_content(tok->data + i + 1, j - 1),
				tok->data + i + j);
		free(tok->data);
		tok->data = tmp;
		return (j);
	}
}

void				ft_lexer_resolve_vars(t_token *toks)
{
	int			i;

	while (toks)
	{
		if (toks->type == T_STRING && toks->subtype != ST_QUOTE)
		{
			i = 0;
			while (toks->data[i])
			{
				if (toks->data[i] == '$')
					i += ft_xxyy(toks, i);
				else
					i += 1;
			}
		}
		toks = toks->next;
	}
}
