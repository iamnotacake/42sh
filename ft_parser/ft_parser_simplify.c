/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_simplify.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:36:22 by alischyn          #+#    #+#             */
/*   Updated: 2017/10/01 15:36:24 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser_private.h"

void			parser_simplify(t_syntax_tree **tree)
{
	t_syntax_tree	*tmp;
	int				i;

	if (!tree || !(*tree))
		return ;
	if ((strcmp((*tree)->type, "list") == 0 ||
		strcmp((*tree)->type, "piped") == 0 ||
		strcmp((*tree)->type, "logic") == 0) &&
		(*tree)->tree[1] == NULL)
	{
		tmp = (*tree)->tree[0];
		free((*tree)->tree);
		free((*tree)->args);
		free(*tree);
		*tree = tmp;
	}
	i = 0;
	while ((*tree)->tree[i])
	{
		parser_simplify(&((*tree)->tree[i]));
		parser_simplify(&((*tree)->tree[i]));
		i += 1;
	}
}
