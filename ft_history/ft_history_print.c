/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:20:03 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/27 17:20:04 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

void	ft_history_in(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (*str)
	{
		ioctl(0, TIOCSTI, str);
		str++;
	}
	while (len--)
		ft_putstr(ARRL);
	len = ft_strlen(str);
	while (len--)
		ft_putstr(" ");
	len = ft_strlen(str);
	while (len--)
		ft_putstr(ARRL);
}

int		ft_history_stdin(t_proc **proc)
{
	if ((*proc)->argv[1])
	{
		ft_history_error(proc, "to match arguments\n");
		return (-1);
	}
	ft_history_in((*proc)->argv[0] + 1);
	return (0);
}

int		ft_history_if(t_proc **proc)
{
	int	st;

	st = -1;
	if (!ft_strcmp("history", (*proc)->argv[0]))
		st = ft_history_stdout_clear(proc);
	else if (!ft_strncmp("!", (*proc)->argv[0], 1))
		st = ft_history_stdin(proc);
	return (st);
}

int		ft_history_print(t_proc **proc)
{
	int	st;
	int	old1;

	st = -1;
	old1 = 0;
	if ((*proc)->dup[1] != 1)
	{
		old1 = dup(1);
		dup2((*proc)->dup[1], 1);
	}
	st = ft_history_if(proc);
	if (old1)
	{
		dup2(old1, 2);
	}
	return (st);
}
