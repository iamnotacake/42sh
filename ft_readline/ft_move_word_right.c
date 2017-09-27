/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_word_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:38:39 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/30 14:38:40 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		ft_find_right(char *rgt)
{
	int	wr;

	wr = 0;
	if (rgt[wr] == ' ')
	{
		while (rgt[wr] && rgt[wr] == ' ')
			wr++;
	}
	else if (rgt[wr] != ' ')
	{
		while (rgt[wr] && rgt[wr] != ' ')
			wr++;
		while (rgt[wr] && rgt[wr] == ' ')
			wr++;
	}
	return (wr);
}

void	ft_move_word_str(char **lft, char **rgt, int r, int find)
{
	char	*tmp;

	if (r > find)
	{
		tmp = ft_strdup((*rgt) + find);
		(*rgt)[find] = '\0';
		if (!(*lft))
			(*lft) = ft_freedup((*rgt), 1);
		else
			(*lft) = ft_freejoin((*lft), (*rgt), 3);
		(*rgt) = ft_freedup(tmp, 1);
	}
	if (r == find)
	{
		if (!(*lft))
			(*lft) = ft_freedup((*rgt), 1);
		else
			(*lft) = ft_freejoin((*lft), (*rgt), 3);
		(*rgt) = NULL;
	}
}

void	ft_move_row_cursor(int row, int pos)
{
	while (row)
	{
		write(1, "\r\n", 2);
		row--;
	}
	while (pos)
	{
		write(1, "\033[C", 3);
		pos--;
	}
}

void	ft_move_word_cursor(int l, int len, int find)
{
	int		pos;
	int		row;
	int		promt;

	promt = ft_strlen(g_promt);
	pos = ((l + promt + find) % len);
	row = ((l + promt + find) / len) - ((l + promt) / len);
	if (!row)
	{
		while (find != 0)
		{
			write(1, "\033[C", 3);
			find--;
		}
	}
	else
		ft_move_row_cursor(row, pos);
}

void	ft_move_word_right(char **lft, char **rgt, int len)
{
	int		l;
	int		r;
	int		find;

	if (!(*rgt))
		return ;
	l = 0;
	if ((*lft))
		l = ft_strlen((*lft));
	r = ft_strlen((*rgt));
	find = ft_find_right((*rgt));
	ft_move_word_str(lft, rgt, r, find);
	ft_move_word_cursor(l, len, find);
}
