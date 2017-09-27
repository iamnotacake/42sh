/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:11:19 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/01 16:11:22 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_clear_liner(int res)
{
	int	r;

	r = 0;
	write(1, "\r", 1);
	while (r != res)
	{
		write(1, " ", 1);
		r++;
	}
	write(1, "\r", 1);
}

void	ft_clear(char **lft, char **rgt)
{
	int	l;
	int	r;
	int	res;

	l = 0;
	r = 0;
	if (*lft)
	{
		l = ft_strlen(*lft);
		free(*lft);
		*lft = NULL;
	}
	if (*rgt)
	{
		r = ft_strlen(*rgt);
		free(*rgt);
		*rgt = NULL;
	}
	res = l + r + 3;
	ft_clear_liner(res);
}

void	ft_history_find(char **lft, char **rgt, t_his *his)
{
	t_his	*tory;

	tory = his;
	ft_clear(lft, rgt);
	ft_putstr("$f_istory> ");
	ft_history_get_tory(lft, his);
	if (!(*lft))
		ft_putstr("\nnothing was inputted\n$> ");
	if ((*lft))
	{
		ft_putstr("\n$> ");
		ft_putstr(*lft);
	}
}
