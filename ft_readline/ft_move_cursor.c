/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:58:18 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 16:02:09 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_move_cursor(char **lft, char **rgt, unsigned long key)
{
	struct winsize	size;
	int				len;

	ioctl(0, TIOCGWINSZ, &size);
	len = size.ws_col;
	if (key == K_LFT)
		ft_move_cursor_left(lft, rgt);
	else if (key == K_RGT)
		ft_move_cursor_right(lft, rgt, len);
}

void	ft_get_line(char **line, t_his **his)
{
	unsigned char	key;

	g_lft = NULL;
	g_rgt = NULL;
	while (read(0, &key, sizeof(key)))
	{
		if (!(ft_char_analysis(key, &g_lft, &g_rgt, his)))
		{
			ft_get_line_save(&g_lft, &g_rgt, line, his);
			return ;
		}
	}
	g_lft = NULL;
	g_rgt = NULL;
}
