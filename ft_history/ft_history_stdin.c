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

char	*ft_history_hi(int n)
{
	t_his	*his;

	if (!(his = ft_history_up()))
		return (NULL);
	while (--n && his)
		his = his->next;
	if (his)
		if (his->next)
			if (!his->next->tory)
				return (NULL);
	if (n == 0 && his)
		if (his->tory)
			return (his->tory);
	return (NULL);
}

char	*ft_history_low(int n)
{
	t_his	*his;

	if (!(his = ft_history_dwn()))
		return (NULL);
	n--;
	while (++n && his)
		his = his->prev;
	if (n == 0 && his)
		if (his->tory)
			return (his->tory);
	return (NULL);
}

char	*ft_history_find_his(int n)
{
	char	*str;

	str = NULL;
	printf("%d\n", n);
	if (n > 0)
		str = ft_history_hi(n);
	else if (n < 0)
		str = ft_history_low(n);
	return (str);
}

int		ft_history_stdin(t_proc **proc)
{
	int		num;
	char	*str;

	if ((*proc)->argv[1])
	{
		ft_history_error(proc, "to match arguments, need only '!...'\n");
		return (-1);
	}
	if (!(num = ft_atoi((*proc)->argv[0] + 1)) ||
		!(str = ft_history_find_his(num)))
	{
		ft_history_error(proc, "event not found\n");
		return (-1);
	}
	ft_history_in(str);
	return (0);
}
