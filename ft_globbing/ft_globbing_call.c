#include "ft_globbing.h"

static int		g_index;

static void		append(t_syntax_tree ***tree, t_syntax_tree *elem)
{
	if (g_index == 0)
		*tree = malloc(sizeof(void *) * 64);
	else if ((g_index & 63) == 0)
		*tree = realloc(*tree, sizeof(void *) * (g_index + 64));
	(*tree)[g_index++] = elem;
}

void			ft_globbing_call(t_syntax_tree *arguments)
{
	int				i;
	t_syntax_tree	**new_tree;
	t_syntax_tree	*elem;
	char			*tmp;

	g_index = 0;
	i = 0;
	while (arguments->tree[i])
	{
		if (strcmp(arguments->tree[i]->type, "string") == 0 &&
			ft_globbing_init(arguments->tree[i]->args[0]))
		{
			syntax_tree_free(arguments->tree[i]);
			while ((tmp = ft_globbing_next()))
			{
				elem = syntax_tree_new("string");
				syntax_tree_append(elem, NULL, tmp);
				append(&new_tree, elem);
			}
		}
		else
			append(&new_tree, arguments->tree[i]);
		i += 1;
	}
}
