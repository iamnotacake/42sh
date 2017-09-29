/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:00:46 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/28 17:00:46 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

static void main_signal_handler(int signo)
{
	(void)signo;
	if (signo == SIGINT && !g_parent)
		exit(0);
	else if (signo == SIGQUIT)
	{
		;
	}
	else if (signo == SIGTSTP && !g_parent)
	{
		signal(SIGTSTP, SIG_DFL);
		ioctl(2, TIOCSTI, "\x1A");
	}
}

static void	input_signal_handler(int signo)
{
	if (signo == SIGQUIT)
		exit(0);
	if (signo == SIGINT)
	{
		free(g_lft);
		free(g_rgt);
		g_lft = NULL;
		g_rgt = NULL;
		write(1, "\n", 1);
		ft_putstr(g_promt);
	}
	return ;
}

void		ft_signals(void)
{
	signal(SIGINT, main_signal_handler);
	signal(SIGQUIT, main_signal_handler);
	signal(SIGTSTP, main_signal_handler);
}

void		ft_signals_input(void)
{
	signal(SIGINT, input_signal_handler);
	signal(SIGQUIT, input_signal_handler);
}
