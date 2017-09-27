/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_save.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:12:25 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/30 21:12:27 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char	*ft_line(char *lft, char *rgt)
{
	if (!lft && !rgt)
		return (NULL);
	else if (!lft)
		return (ft_freedup(rgt, 1));
	else if (!rgt)
		return (ft_freedup(lft, 1));
	else
		return (ft_freejoin(lft, rgt, 3));
}

void	ft_till_the_end(char **lft, char **rgt)
{
	struct winsize	size;
	int				len;

	ioctl(0, TIOCGWINSZ, &size);
	len = size.ws_col;
	ft_move_end(lft, rgt, len);
}

void	ft_get_line_save(char **lft, char **rgt, char **line, t_his **his)
{
	ft_till_the_end(lft, rgt);
	(*line) = ft_line((*lft), (*rgt));
	if ((*line))
		if (ft_strlen((*line)) != 0)
			ft_add_to_history(his, *line);
	if ((*his))
		ft_free_tmp(his);
}
