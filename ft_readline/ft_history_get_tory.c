/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_get_tory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:41:15 by olyuboch          #+#    #+#             */
/*   Updated: 2017/07/01 16:41:17 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline_private.h"

void	ft_history_backslash(char **lft)
{
	char	*tmp;
	int		l;

	if (!(*lft))
		return ;
	l = ft_strlen((*lft));
	write(1, "\033[D \033[D", 7);
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
}

void	ft_history_lft(char **new, char *buf)
{
	char	*tmp;

	if (!(*new))
		(*new) = ft_strdup(buf);
	else
	{
		tmp = ft_freejoin((*new), buf, 1);
		(*new) = ft_freedup(tmp, 1);
	}
}

void	ft_history_new_line(char **new, char **lft, char *buf)
{
	if (*new)
	{
		*lft = ft_strdup((*new));
	}
	free(buf);
}

int		ft_char_analys(char **new, char *buf, char **lft, t_his *his)
{
	if (*lft)
		ft_putstr("");
	if (!ft_strcmp(buf, "\n"))
	{
		ft_history_new_line(new, lft, buf);
		return (0);
	}
	else if (!ft_strcmp(buf, "\x7f"))
		ft_history_backslash(new);
	else if (!ft_strcmp(buf, "\t") && his)
	{
		ft_history_check(new, his);
	}
	else if (*buf > 31 && *buf < 127)
	{
		ft_history_lft(new, buf);
		if (!(*new))
			(*new) = ft_strdup(buf);
		ft_putstr(buf);
	}
	return (1);
}

void	ft_history_get_tory(char **lft, t_his *his)
{
	t_his	*tory;
	char	*buf;
	char	*new;

	tory = his;
	if (!(buf = (char *)malloc(sizeof(char) * (READ_SIZE + 1))))
		return ;
	ft_bzero(buf, (READ_SIZE));
	buf[READ_SIZE] = '\0';
	new = NULL;
	while (read(0, buf, READ_SIZE))
	{
		if (!ft_char_analys(&new, buf, lft, his))
		{
			if (new)
				free(new);
			return ;
		}
		ft_bzero(buf, (READ_SIZE));
		buf[READ_SIZE] = '\0';
	}
}
