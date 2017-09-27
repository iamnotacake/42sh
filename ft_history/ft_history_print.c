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

int	ft_history_stdin(char **argv)
{
	char	*str;
	int		len;

	if (argv[1])
	{
		len = ft_strlen(argv[1]);
		str = argv[1];
		while (*str)
		{
			ioctl(0, TIOCSTI, str);
			str++;
		}
		while (len--)
			ft_putstr(ARRL);
		len = ft_strlen(argv[1]);
		while (len--)
			ft_putstr(" ");
		len = ft_strlen(argv[1]);
		while (len--)
			ft_putstr(ARRL);
	}
	return (0);
}

void	ft_history_error(t_proc **proc, char *er)
{
	int	old2;

	old2 = 0;
	if ((*proc)->dup[2] != 2)
	{
		old2 = dup(2);
		dup2((*proc)->dup[2], 2);
	}
	ft_putstr_fd("wtf?: ", 2);
	ft_putstr_fd(er, 2);
	// ft_putendl_fd((*proc)->argv[0], 2);
	if (old2)
	{
		dup2(old2, 2);
		// close((*proc)->dup[2]);
	}
}

int	ft_history_write_clear(char **argv)
{
	t_his	*his;

	his = g_history;
	while (his->prev)
		his = his->prev;
}

int	ft_history_if(t_proc **proc)
{
	int	st;

	st = -1;
	if (!ft_strcmp("history", (*proc)->argv[0]))
		st = ft_history_write_clear((*proc)->argv);
	else if ((*proc)->argv[2])
	{
		ft_history_error(proc, "to match arguments\n");
		return (-1);
	}
	if (!ft_strncmp("!", (*proc)->argv[0], 1))
		st = ft_history_stdin((*proc)->argv);
	return (st);
}

int	ft_history_print(t_proc **proc)
{
	int	st;
	int	old1;

	st = -1;
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
