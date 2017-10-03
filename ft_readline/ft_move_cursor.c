/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:58:18 by olyuboch          #+#    #+#             */
/*   Updated: 2017/10/01 16:39:33 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

extern char	*g_lft;
extern char	*g_rgt;
extern char	*g_heredoc;

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

int		ft_get_line_is_exit(char **line)
{
	if ((!g_lft || !g_lft[0]) && (!g_rgt || !g_rgt[0]))
	{
		if (g_heredoc)
		{
			(*line) = ft_strdup(g_heredoc);
			g_heredoc = NULL;
			return (0);
		}
		ft_terminal_set();
		exit(0);
	}
	return (1);
}
