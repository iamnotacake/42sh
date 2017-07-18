/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_line_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:32:30 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/30 19:32:32 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

void	ft_move_line_str(char **lft, char **rgt, int r, int len)
{
	char	*tmp;

	if (r <= len)
	{
		if ((*lft))
			(*lft) = ft_freejoin((*lft), (*rgt), 3);
		else
			(*lft) = ft_freedup((*rgt), 1);
		(*rgt) = NULL;
	}
	else
	{
		tmp = ft_strdup((*rgt) + len);
		(*rgt)[len] = '\0';
		if ((*lft))
			(*lft) = ft_freejoin((*lft), (*rgt), 1);
		else
			(*lft) = ft_strdup((*rgt));
		free((*rgt));
		(*rgt) = ft_freedup(tmp, 1);
	}
}

void	ft_move_line_cursor(int l, int find, int len)
{
	int	pos;
	int	row;

	pos = ((l + 3 + find) % len);
	row = ((l + 3 + find) / len) - ((l + 3) / len);
	if (!row)
	{
		while (find != 0)
		{
			write(1, "\033[C", 3);
			find--;
		}
	}
	else
	{
		write(1, "\r\n", 2);
		while (pos)
		{
			write(1, "\033[C", 3);
			pos--;
		}
	}
}

void	ft_move_line_down(char **lft, char **rgt, int len)
{
	int	l;
	int	r;
	int	find;

	if (!(*rgt))
		return ;
	l = 0;
	if ((*lft))
		l = ft_strlen((*lft));
	r = ft_strlen((*rgt));
	if (r >= len)
		find = len;
	else
		find = r;
	ft_move_line_str(lft, rgt, r, len);
	ft_move_line_cursor(l, find, len);
}
