/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 13:51:04 by olyuboch          #+#    #+#             */
/*   Updated: 2017/04/26 13:51:05 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_re_print(char *rgt)
{
	size_t	r;
	size_t	i;

	r = ft_strlen(rgt);
	i = 0;
	while (i < (r - 1))
	{
		write(1, " ", 1);
		i++;
	}
	while (i > 0)
	{
		write(1, "\033[D", 3);
		i--;
	}
	ft_putstr(rgt);
	while (i < r)
	{
		write(1, "\033[D", 3);
		i++;
	}
}

void	ft_if_printchar(char **lft, char **rgt, char *buf)
{
	char	*tmp;

	ft_putstr(buf);
	if (!(*lft))
		(*lft) = ft_strdup(buf);
	else
	{
		tmp = ft_strdup((*lft));
		free((*lft));
		(*lft) = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if ((*rgt))
		ft_re_print(*rgt);
}

void	ft_move_escape(char **lft, char **rgt, t_his **his)
{
	unsigned long	key;

	key = 0;
	if (read(0, &key, sizeof(key)))
	{
		if (key == K_LFT || key == K_RGT)
			ft_move_cursor(lft, rgt, key);
		else if (key == K_UP || key == K_DWN)
			ft_move_history(key, lft, rgt, his);
		else if (key == K_SHT_RGT || key == K_SHT_LFT)
			ft_move_begin_end(lft, rgt, key);
		else if (key == K_ALT_RGT || key == K_ALT_LFT)
			ft_move_words(lft, rgt, key);
		else if (key == K_ALT_UP || key == K_ALT_DWN)
			ft_move_line(lft, rgt, key);
	}
}

int		ft_char_analysis(unsigned char key, char **lft, char **rgt, t_his **his)
{
	char	*buf;

	if (key == '\n')
		return (0);
	else if (key == ESC)
	{
		ft_move_escape(lft, rgt, his);
	}
	else if (key == K_BACKSP)
			ft_move_backslash(lft, rgt);
	else if (key == K_CTR_R)
		ft_history_find(lft, rgt, *his);
	else if (key == '\t')
		ft_move_tab(lft, rgt);
	else if (ft_isascii(key) && key)
	{
		if (!(buf = (char *)malloc(sizeof(char) * (READ_SIZE + 1))))
			return (0);
		ft_bzero(buf, (READ_SIZE));
		buf[READ_SIZE] = '\0';
		buf[0] = key;
		ft_if_printchar(lft, rgt, buf);
		free(buf);
	}
	return (1);
}

void	ft_free_all(char *buf, char **lft, char **rgt)
{
	if (buf)
		free(buf);
	if (*lft)
	{
		free(*lft);
		(*lft) = NULL;
	}
	if (*rgt)
	{
		free(*rgt);
		(*rgt) = NULL;
	}
}

void	ft_get_line(char **line, t_his **his)
{
	unsigned char	key;
	char			*lft;
	char			*rgt;

	lft = NULL;
	rgt = NULL;
	while (read(0, &key, sizeof(key)))
	{
		if (!(ft_char_analysis(key, &lft, &rgt, his)))
		{
			ft_get_line_save(&lft, &rgt, line, his);
			return ;
		}
	}
}
