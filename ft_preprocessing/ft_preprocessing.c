/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 09:41:43 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/05 09:41:45 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"
# include "ft_parser.h"
# include "ft_exec.h"
# include "ft_lexer.h"

# include <stdio.h>

void	ft_preprocessing(t_syntax_tree *tree, int e)
{
	int 	i;

	i = 0;
	if (tree == NULL)
		return ;
	printf("type: %s\n", tree->type);
	while (tree->args[i])
	{
		printf("arg[%d]: %s\n", i, tree->args[i]);
		i++;
	}
	i = 0;
	while (tree->tree[i])
	{
		if (tree->tree[i])
			ft_preprocessing(tree->tree[i], e + 1);
		i++;
	}
}