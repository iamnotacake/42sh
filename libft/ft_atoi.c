/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyuboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:13:35 by olyuboch          #+#    #+#             */
/*   Updated: 2016/12/19 21:29:05 by olyuboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*ft_znak(unsigned char *s)
{
	int	i;

	i = 1;
	while (*s == ' ' || *s == '\t' || *s == '\v'
			|| *s == '\f' || *s == '\r' || *s == '\n')
		s++;
	return (s);
}

int						ft_atoi(const char *str)
{
	int					i;
	unsigned char		*nstr;
	unsigned long int	num;

	num = 0;
	i = 1;
	nstr = ft_znak((unsigned char *)str);
	if (*nstr == '-' || *nstr == '+')
	{
		if (*nstr == '-')
			i = -1;
		nstr++;
	}
	while (ft_isdigit(*nstr))
	{
		if ((num > 922337203685477580 || (num == 922337203685477580
			&& (*nstr - '0') > 7)) && i == 1)
			return (-1);
		else if ((num > 922337203685477580 || (num == 922337203685477580
			&& (*nstr - '0') > 8)) && i == -1)
			return (0);
		num = num * 10 + (*nstr++ - '0');
	}
	return (num * i);
}
