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

#include "ft_readline_private.h"

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

int		ft_char_analysis(char *buf, char **lft, char **rgt, t_his **his)
{
	if (!ft_strcmp(buf, "\n"))
		return (0);
	else if (!ft_strcmp(buf, ARRL) || !ft_strcmp(buf, ARRR))
		ft_move_cursor(lft, rgt, buf);
	else if (!ft_strcmp(buf, ARRU) || !ft_strcmp(buf, ARRD))
		ft_move_history(buf, lft, rgt, his);
	else if (!ft_strcmp(buf, "\x7f"))
		ft_move_backslash(lft, rgt);
	else if (!ft_strcmp(buf, SHTR) || !ft_strcmp(buf, SHTL))
		ft_move_begin_end(lft, rgt, buf);
	else if (!ft_strcmp(buf, ALTR) || !ft_strcmp(buf, ALTL))
		ft_move_words(lft, rgt, buf);
	else if (!ft_strcmp(buf, ALTU) || !ft_strcmp(buf, ALTD))
		ft_move_line(lft, rgt, buf);
	else if (!ft_strcmp(buf, "\t"))
		ft_move_tab(lft, rgt);
	else if (!ft_strcmp(buf, "\x12"))
	{
		ft_history_find(lft, rgt, *his);
		return (1);
	}
	else
		ft_if_printchar(lft, rgt, buf);
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
	char	*buf;
	char	*lft;
	char	*rgt;

	lft = NULL;
	rgt = NULL;
	if (!(buf = (char *)malloc(sizeof(char) * (READ_SIZE + 1))))
		return ;
	ft_bzero(buf, (READ_SIZE));
	buf[READ_SIZE] = '\0';
	while (read(0, buf, READ_SIZE))
	{
		if (!(ft_char_analysis(buf, &lft, &rgt, his)))
		{
			free(buf);
			ft_get_line_save(&lft, &rgt, line, his);
			return ;
		}
		ft_bzero(buf, READ_SIZE);
		buf[READ_SIZE] = '\0';
	}
}
