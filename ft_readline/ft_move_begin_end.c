/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_begin_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:04:31 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/29 12:04:32 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_move_begin(char **lft, char **rgt)
{
	int	l;

	if (!(*lft))
		return ;
	l = ft_strlen((*lft));
	if (!(*rgt))
		(*rgt) = ft_freedup((*lft), 1);
	else
		(*rgt) = ft_freejoin((*lft), (*rgt), 3);
	(*lft) = NULL;
	while (l != 0)
	{
		write(1, "\033[D", 3);
		l--;
	}
}

void	ft_move_down_the_row(int row, int pos)
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

void	ft_move_row(int r, int l, int len)
{
	int		pos;
	int		row;
	int		promt;

	promt = ft_strlen(g_promt);
	pos = ((l + promt + r) % len);
	row = ((l + promt + r) / len) - ((l + promt) / len);
	if (!row)
	{
		while (r != 0)
		{
			write(1, "\033[C", 3);
			r--;
		}
	}
	else
		ft_move_down_the_row(row, pos);
}

void	ft_move_end(char **lft, char **rgt, int len)
{
	int	r;
	int	l;

	if (!(*rgt))
		return ;
	l = 0;
	r = ft_strlen((*rgt));
	if (!(*lft))
		(*lft) = ft_freedup((*rgt), 1);
	else
	{
		l = ft_strlen((*lft));
		(*lft) = ft_freejoin((*lft), (*rgt), 3);
	}
	(*rgt) = NULL;
	ft_move_row(r, l, len);
}

void	ft_move_begin_end(char **lft, char **rgt, unsigned long key)
{
	struct winsize	size;
	int				len;

	ioctl(0, TIOCGWINSZ, &size);
	len = size.ws_col;
	if (key == K_SHT_LFT)
		ft_move_begin(lft, rgt);
	if (key == K_SHT_RGT)
	{
		ft_move_end(lft, rgt, len);
	}
}
