/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:30:53 by olyuboch          #+#    #+#             */
/*   Updated: 2017/04/30 13:30:55 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_clear_line(char *lft, char *rgt)
{
	size_t	r;
	size_t	l;
	size_t	t;

	t = 0;
	if (rgt)
	{
		r = ft_strlen(rgt);
		while (t++ != r)
			write(1, " ", 1);
		while (t-- != 1)
			write(1, "\033[D", 3);
	}
	t = 0;
	if (lft)
	{
		l = ft_strlen(lft);
		while (t++ != l)
			write(1, "\033[D", 3);
		while (t-- != 0)
			write(1, " ", 1);
		while (t++ != l)
			write(1, "\033[D", 3);
	}
}

/*
**	if (!ft_add_to_tmp(lft, rgt, his))
**		(*his)->tmp = ft_strdup("");
*/

void	ft_arrow_up(char **lft, char **rgt, t_his **his)
{
	ft_add_to_tmp(lft, rgt, his);
	if ((*his)->prev)
	{
		ft_clear_line(*lft, *rgt);
		(*his) = (*his)->prev;
		if ((*lft))
			free((*lft));
		if ((*rgt))
		{
			free((*rgt));
			(*rgt) = NULL;
		}
		if ((*his)->tmp)
			(*lft) = ft_strdup((*his)->tmp);
		else
			(*lft) = ft_strdup((*his)->tory);
		ft_putstr((*lft));
	}
}

void	ft_arrow_down(char **lft, char **rgt, t_his **his)
{
	ft_add_to_tmp(lft, rgt, his);
	if ((*his)->next)
	{
		ft_clear_line(*lft, *rgt);
		(*his) = (*his)->next;
		if ((*lft))
		{
			free((*lft));
			(*lft) = NULL;
		}
		if ((*rgt))
		{
			free((*rgt));
			(*rgt) = NULL;
		}
		if ((*his)->tmp)
			(*lft) = ft_strdup((*his)->tmp);
		if ((*lft))
			ft_putstr((*lft));
	}
}

void	ft_move_history(unsigned long key, char **lft, char **rgt, t_his **his)
{
	if (key == K_UP && (*his))
		ft_arrow_up(lft, rgt, his);
	if (key == K_DWN && (*his))
		ft_arrow_down(lft, rgt, his);
}
