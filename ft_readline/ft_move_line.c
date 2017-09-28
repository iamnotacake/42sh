/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:48:35 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/29 12:48:38 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_move_line_up_str(char **lft, char **rgt, int l, int len)
{
	char	*tmp;

	if (l <= len)
	{
		if (!(*rgt))
			(*rgt) = ft_freedup((*lft), 1);
		else
			(*rgt) = ft_freejoin((*lft), (*rgt), 3);
		(*lft) = NULL;
	}
	else
	{
		if (!(*rgt))
			(*rgt) = ft_strdup((*lft) + l - len);
		else
		{
			tmp = ft_freejoin((*lft) + l - len, (*rgt), 2);
			(*rgt) = ft_freedup(tmp, 1);
		}
		(*lft)[l - len] = '\0';
		tmp = ft_freedup((*lft), 1);
		(*lft) = ft_freedup(tmp, 1);
	}
}

void	ft_move_line_up_cursor(int l, int len)
{
	int	find;

	if (l >= len)
		find = len;
	else
		find = l;
	while (find)
	{
		write(1, "\033[D", 3);
		find--;
	}
}

void	ft_move_line_up(char **lft, char **rgt, int len)
{
	int	l;

	if (!(*lft))
		return ;
	l = ft_strlen((*lft));
	ft_move_line_up_str(lft, rgt, l, len);
	ft_move_line_up_cursor(l, len);
}

void	ft_move_line(char **lft, char **rgt, unsigned long key)
{
	struct winsize	size;
	int				len;

	ioctl(0, TIOCGWINSZ, &size);
	len = size.ws_col;
	if (key == K_ALT_UP)
		ft_move_line_up(lft, rgt, len);
	if (key == K_ALT_DWN)
		ft_move_line_down(lft, rgt, len);
}
