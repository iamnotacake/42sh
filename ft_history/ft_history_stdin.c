/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:16:14 by olyuboch          #+#    #+#             */
/*   Updated: 2017/09/28 16:16:16 by olyuboch         ###   ########.fr       */
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
		ft_history_error(proc, "to match arguments, need only '!...'\n");
		return (-1);
	}
	ft_history_in((*proc)->argv[0] + 1);
	return (0);
}
