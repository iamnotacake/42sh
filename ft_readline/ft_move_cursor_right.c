/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:00:32 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/31 10:00:35 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_without_left(char **lft, char **rgt)
{
	char	*tmp;

	tmp = NULL;
	write(1, "\033[C", 3);
	if ((*rgt)[1] != '\0')
	{
		tmp = ft_strdup((*rgt) + 1);
		(*rgt)[1] = '\0';
	}
	(*lft) = ft_freedup((*rgt), 1);
	(*rgt) = NULL;
	if (tmp)
		(*rgt) = ft_freedup(tmp, 1);
}

void	ft_l_d(int len)
{
	while (len)
	{
		write(1, "\033[D", 3);
		len--;
	}
	write(1, "\033[B", 3);
}

void	ft_move_rgt(int l, int len)
{
	int		pos;

	pos = ((l + ft_strlen(g_promt) + 1) % len);
	if (pos == 0)
		write(1, "\r\n", 2);
	else
		write(1, "\033[C", 3);
}

void	ft_lft_vs_rgt(char **lft, char **rgt, int len)
{
	char	*tmpr;
	char	*tmpl;
	int		r;
	int		l;

	l = ft_strlen((*lft));
	r = ft_strlen((*rgt));
	tmpr = NULL;
	if ((*rgt)[1] != '\0')
	{
		tmpr = ft_strdup((*rgt) + 1);
		(*rgt)[1] = '\0';
	}
	tmpl = ft_freedup((*lft), 1);
	(*lft) = ft_freejoin(tmpl, (*rgt), 3);
	(*rgt) = NULL;
	if (tmpr)
		(*rgt) = ft_freedup(tmpr, 1);
	ft_move_rgt(l, len);
}

void	ft_move_cursor_right(char **lft, char **rgt, int len)
{
	if (!(*rgt))
		return ;
	else if (!(*lft) && (*rgt))
		ft_without_left(lft, rgt);
	else if ((*lft) && (*rgt))
		ft_lft_vs_rgt(lft, rgt, len);
}
