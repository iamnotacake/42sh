/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_backslash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:41:16 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/03 16:41:18 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_del_right(char *rgt)
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

void	ft_print_right(char *rgt)
{
	int	r;

	r = ft_strlen(rgt);
	ft_putstr(rgt);
	while (r-- != 0)
		write(1, "\033[D", 3);
}

void	ft_move_backslash(char **lft, char **rgt)
{
	char	*tmp;
	int		l;

	if (!(*lft))
		return ;
	if ((*rgt))
		ft_del_right(*rgt);
	l = ft_strlen((*lft));
	write(1, "\033[D", 3);
	write(1, " ", 1);
	write(1, "\033[D", 3);
	if (l > 1)
	{
		(*lft)[l - 1] = '\0';
		tmp = ft_freedup((*lft), 1);
		(*lft) = ft_freedup(tmp, 1);
	}
	else if (l == 1)
	{
		free((*lft));
		(*lft) = NULL;
	}
	if ((*rgt))
		ft_print_right(*rgt);
}
