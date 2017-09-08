/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:58:18 by olyuboch          #+#    #+#             */
/*   Updated: 2017/04/29 17:58:20 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

void	ft_move_cursor(char **lft, char **rgt, char *buf)
{
	struct winsize	size;
	int				len;

	ioctl(0, TIOCGWINSZ, &size);
	len = size.ws_col;
	if (!ft_strcmp(buf, ARRL))
		ft_move_cursor_left(lft, rgt);
	else if (!ft_strcmp(buf, ARRR))
		ft_move_cursor_right(lft, rgt, len);
}
