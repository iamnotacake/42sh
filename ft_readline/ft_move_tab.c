/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:23:38 by olyuboch          #+#    #+#             */
/*   Updated: 2017/06/29 14:23:39 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

void	ft_del_rgt(char *rgt)
{
	int	r;
	int	t;

	t = 0;
	r = ft_strlen(rgt);
	while (t++ != r)
		write(1, " ", 1);
	while (t-- != 1)
		write(1, "\033[D", 3);
}

void	ft_print_rgt(char *rgt)
{
	int	r;

	r = ft_strlen(rgt);
	ft_putstr(rgt);
	while (r-- != 0)
		write(1, "\033[D", 3);
}

int		ft_check_left(char *lft)
{
	int	i;
	int	l;

	i = 0;
	if (!lft)
		return (0);
	else
	{
		l = ft_strlen(lft) - 1;
		if (lft[l] == ' ')
			return (0);
		while (l != 0 && lft[l] != ' ')
		{
			l--;
		}
		if (l != 0)
			return (l + 1);
	}
	return (0);
}

void	ft_move_tab(char **lft, char **rgt)
{
	int		sp;
	int		l;

	if ((*rgt) && (*rgt)[0] != ' ')
		return ;
	if (!(sp = ft_check_left(*lft)))
		return ;
	l = ft_strlen(*lft);
	ft_tab_cut(lft, sp, l);
	if ((*rgt))
	{
		ft_del_rgt(*rgt);
		ft_print_rgt(*rgt);
	}
}
