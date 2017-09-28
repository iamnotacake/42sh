/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_stdout_clear.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:50:34 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/28 10:51:17 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"
#include "ft_free.h"

t_his	*ft_history_up()
{
	t_his	*his;

	his = g_history;
	if (!his)
		return (NULL);
	while (his->prev)
		his = his->prev;
	return (his);
}

void	ft_history_out(void)
{
	t_his	*his;

	if (!(his = ft_history_up()))
		return ;
	while (his)
	{
		ft_putendl(his->tory);
		his = his->next;
	}
}

void	ft_history_clear(void)
{
	int	fl;

	fl = O_TRUNC;
	ft_free_history();
	ft_history_load(NULL, fl);
}

int		ft_history_stdout_clear(t_proc **proc)
{
	char	*err;

	if (!(*proc)->argv[1])
	{
		ft_history_out();
		return (0);
	}
	else if (!ft_strcmp((*proc)->argv[1], "-c"))
		ft_history_clear();
	else
	{
		err = ft_strjoin("event not found: ", (*proc)->argv[1]);
		ft_history_error(proc, err);
		ft_putstr("\n");
		free(err);
		return (-1);
	}
	return (0);
}
