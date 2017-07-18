/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor_left.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:55:19 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/31 09:55:21 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

void	ft_without_right(char **lft, char **rgt)
{
	size_t	l;
	char	*tmp;

	write(1, "\033[D", 3);
	l = ft_strlen((*lft));
	(*rgt) = ft_strdup((*lft) + l - 1);
	(*lft)[l - 1] = '\0';
	tmp = ft_freedup((*lft), 1);
	(*lft) = ft_freedup(tmp, 1);
	if (l == 1)
	{
		free((*lft));
		(*lft) = NULL;
	}
}

void	ft_left_vs_right(char **lft, char **rgt)
{
	size_t	l;
	char	*tmp;

	write(1, "\033[D", 3);
	l = ft_strlen((*lft));
	tmp = ft_freedup((*rgt), 1);
	if (l == 1)
	{
		(*rgt) = ft_freejoin((*lft), tmp, 3);
		(*lft) = NULL;
	}
	else
	{
		(*rgt) = ft_freejoin((*lft) + l - 1, tmp, 2);
		(*lft)[l - 1] = '\0';
		tmp = ft_freedup((*lft), 1);
		(*lft) = ft_freedup(tmp, 1);
	}
}

void	ft_move_cursor_left(char **lft, char **rgt)
{
	if (!(*lft))
		return ;
	else if (!(*rgt) && (*lft))
		ft_without_right(lft, rgt);
	else if ((*lft) && (*rgt))
		ft_left_vs_right(lft, rgt);
}
