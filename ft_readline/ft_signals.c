/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:59:42 by olyuboch          #+#    #+#             */
/*   Updated: 2017/05/31 13:59:44 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	sigint_handler(int signo)
{
	(void)signo;
	if (signo == SIGQUIT)
		exit(signo);
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		ft_putstr(g_promt);
	}
	return ;
}

void		ft_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigint_handler);
}
