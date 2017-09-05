/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:19:05 by olyuboch          #+#    #+#             */
/*   Updated: 2017/08/14 18:19:07 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

int		ft_count_mas(char **argv)
{
	int	n;

	n = 0;
	while (argv[n])
		n++;
	return (n);
}

void	ft_realloc_arg(t_syntax_tree *tree, t_proc **proc)
{
	char	**mas;
	int		n;

	n = ft_count_mas((*proc)->argv);
	if (!(mas = (char **)malloc(sizeof(char *) * (n + 2))))
		return ;
	mas[n + 1] = NULL;
	mas[n] = tree->args[0];
	while (--n >= 0)
		mas[n] = (*proc)->argv[n];
	free((*proc)->argv);
	(*proc)->argv = mas;
}

void	ft_pre_string(t_syntax_tree *tree, t_proc **proc)
{
	char	**mas;

	if (tree == NULL)
		return ;
	if (!(*proc)->argv)
	{
		if (!(mas = (char **)malloc(sizeof(char *) * 2)))
			return ;
		mas[0] = tree->args[0];
		mas[1] = NULL;
		(*proc)->argv = mas;
	}
	else
		ft_realloc_arg(tree, proc);
}
