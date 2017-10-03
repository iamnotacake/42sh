/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globbing_call.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:47:11 by mvarga            #+#    #+#             */
/*   Updated: 2017/10/01 15:16:39 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_globbing.h"

int				g_index;
t_syntax_tree	*g_tree;

static int		ptr_arr_len(t_syntax_tree **ptrs)
{
	int			i;

	i = 0;
	while (ptrs[i])
		i += 1;
	return (i);
}

static void		ptr_arr_remove(t_syntax_tree **tree, int index)
{
	int			len;

	len = ptr_arr_len(tree);
	memmove(&tree[index],
			&tree[index + 1],
			sizeof(void *) * (len - index + 1));
}

static void		**ptr_arr_insert(void **ptrs, int index, void *ptr)
{
	int			len;

	len = ptr_arr_len((t_syntax_tree **)ptrs);
	ptrs = realloc(ptrs, sizeof(void *) * (len + 2));
	memmove((void *)&ptrs[index + 1],
			(void *)&ptrs[index],
			sizeof(void *) * (len - index + 1));
	ptrs[index] = ptr;
	return (ptrs);
}

void			ft_globbing_callback(char *str)
{
	t_syntax_tree	*elem;

	elem = syntax_tree_new("string");
	syntax_tree_append(elem, NULL, str);
	g_tree->tree = (t_syntax_tree **)ptr_arr_insert((void **)g_tree->tree,
													g_index, elem);
	g_index += 1;
}

void			ft_globbing_call(t_syntax_tree *arguments)
{
	char		*tmp;

	ft_tilda_exchange(arguments);
	g_index = 0;
	g_tree = arguments;
	while (arguments->tree[g_index])
	{
		if (arguments->tree[g_index]->need_globbing &&
			arguments->tree[g_index]->args[0] &&
			ft_globbing_is_pattern(arguments->tree[g_index]->args[0]))
		{
			tmp = ft_strdup(arguments->tree[g_index]->args[0]);
			syntax_tree_free(arguments->tree[g_index]);
			ptr_arr_remove(arguments->tree, g_index);
			free(tmp);
		}
		else
			g_index += 1;
	}
}
