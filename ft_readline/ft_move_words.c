/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:30:28 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/29 12:30:29 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		ft_find_left(char *lft, int l)
{
	int	wr;

	wr = 0;
	if (lft[l])
	{
		if (lft[l] != ' ')
		{
			while (l >= wr && lft[l - wr] != ' ')
				wr++;
		}
		else if (lft[l] == ' ')
		{
			while (l >= wr && lft[l - wr] == ' ')
				wr++;
			while (l >= wr && lft[l - wr] != ' ')
				wr++;
		}
	}
	return (wr);
}

void	ft_move_left(char **lft, char **rgt)
{
	int	l;
	int	wr;

	if (!(*lft))
		return ;
	l = ft_strlen((*lft));
	wr = ft_find_left((*lft), l - 1);
	if (!(*rgt))
		(*rgt) = ft_strdup((*lft) + l - wr);
	else
		(*rgt) = ft_freejoin((*lft) + l - wr, (*rgt), 2);
	if (l == wr)
	{
		free((*lft));
		(*lft) = NULL;
	}
	if (l != wr)
	{
		(*lft)[l - wr] = '\0';
		(*lft) = ft_freedup((*lft), 1);
	}
	while (wr--)
		write(1, "\033[D", 3);
}

void	ft_move_words(char **lft, char **rgt, unsigned long key)
{
	struct winsize	size;
	int				len;

	ioctl(0, TIOCGWINSZ, &size);
	len = size.ws_col;
	if (key == K_ALT_LFT)
		ft_move_left(lft, rgt);
	if (key == K_ALT_RGT)
		ft_move_word_right(lft, rgt, len);
}
