/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_tmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:11:32 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/05 14:11:33 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char	*ft_cmp_left_right(char *left, char *right)
{
	if (!left && !right)
		return (NULL);
	else if (!left)
		return (ft_freedup(right, 0));
	else if (!right)
		return (ft_freedup(left, 0));
	else
		return (ft_freejoin(left, right, 0));
}

int		ft_add_to_tmp(char **lft, char **rgt, t_his **his)
{
	char	*tmp;

	if ((tmp = ft_cmp_left_right(*lft, *rgt)))
	{
		if ((*his)->tmp)
			free((*his)->tmp);
		(*his)->tmp = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

void	ft_free_tmp(t_his **his)
{
	t_his	*new;

	new = (*his);
	if (new->tmp)
	{
		free(new->tmp);
		new->tmp = NULL;
	}
	while (new->prev)
	{
		new = new->prev;
		if (new->tmp)
		{
			free(new->tmp);
			new->tmp = NULL;
		}
	}
}
