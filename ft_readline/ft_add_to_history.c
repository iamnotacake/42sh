/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:51:02 by olyuboch          #+#    #+#             */
/*   Updated: 2017/04/30 13:51:04 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_add_next(t_his **his)
{
	t_his	*next;

	if (!(next = (t_his *)malloc(sizeof(t_his))))
		return ;
	next->tory = NULL;
	next->tmp = NULL;
	next->next = NULL;
	next->prev = (*his);
	(*his)->next = next;
}

void	ft_add_first(t_his **his, char *line)
{
	t_his	*new;

	if (!(new = (t_his *)malloc(sizeof(t_his))))
		return ;
	new->tory = ft_strdup(line);
	new->tmp = NULL;
	new->next = NULL;
	new->prev = NULL;
	(*his) = new;
	ft_add_next(his);
}

void	ft_history_down(t_his **his)
{
	if ((*his))
	{
		while ((*his)->next)
			(*his) = (*his)->next;
	}
}

void	ft_add_to_history(t_his **his, char *line)
{
	// int	fl;

	// fl = O_APPEND;
	if (!(*his))
		ft_add_first(his, line);
	else
	{
		ft_history_down(his);
		(*his)->tory = ft_strdup(line);
		ft_add_next(his);
	}
	ft_history_down(his);
	// ft_history_load(line, fl);
}
