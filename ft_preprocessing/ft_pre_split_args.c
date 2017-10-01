/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_split_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:44:59 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/20 16:45:01 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_preprocessing_private.h"

int		ft_pre_count_args(char **sp, char **argv)
{
	int	s;
	int	a;

	s = 0;
	a = 0;
	while (sp[s])
		s++;
	if (argv)
	{
		while (argv[a])
			a++;
	}
	return (a + s);
}

void	ft_pre_realloc_copy(char **sp, t_proc **proc, char ***mas)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if ((*proc)->argv)
	{
		while ((*proc)->argv[i])
		{
			(*mas)[c] = ft_strdup((*proc)->argv[i]);
			i++;
			c++;
		}
	}
	i = 0;
	while (sp[i])
	{
		(*mas)[c] = ft_strdup(sp[i]);
		i++;
		c++;
	}
}

void	ft_pre_realloc_args(char **sp, t_proc **proc)
{
	int		c;
	char	**mas;

	c = 0;
	if (!(c = ft_pre_count_args(sp, (*proc)->argv)))
		return ;
	if (!(mas = (char **)malloc(sizeof(char *) * (c + 1))))
		return ;
	mas[c] = NULL;
	ft_pre_realloc_copy(sp, proc, &mas);
	if ((*proc)->argv)
		ft_free_mas((*proc)->argv);
	(*proc)->argv = mas;
}

void	ft_pre_split_args(char *str, t_proc **proc)
{
	int		i;
	char	**sp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
	if (!(sp = ft_strsplit(str, ' ')))
		return ;
	ft_pre_realloc_args(sp, proc);
	ft_free_mas(sp);
}
