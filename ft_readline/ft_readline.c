/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:59:55 by alischyn          #+#    #+#             */
/*   Updated: 2017/10/01 15:59:56 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"
#include "ft_signals.h"

void			ft_terminal_set(void)
{
	struct termios	termios;

	tcgetattr(2, &termios);
	termios.c_lflag = (termios.c_lflag ^ ICANON) ^ ECHO;
	tcsetattr(2, TCSANOW, &termios);
}

char			*ft_readline(void)
{
	char		*line;

	line = NULL;
	ft_signals_input();
	ft_terminal_set();
	ft_putstr(g_promt);
	ft_get_line(&line, &g_history);
	ft_terminal_set();
	ft_signals();
	return (line);
}
